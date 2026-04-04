#ifndef LEETCODE_EXCELSUMFORMULA_HPP
#define LEETCODE_EXCELSUMFORMULA_HPP

#include <cstdint>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// LeetCode 631 — Design Excel Sum Formula
// Namespaced so `class Solution` does not ODR-collide in the unified test binary.
namespace lc631 {

inline long long cellKey(int row, int col) {
    return (static_cast<long long>(row) << 32) | static_cast<std::uint32_t>(col);
}

inline void unpackCell(long long key, int &row, int &col) {
    row = static_cast<int>(key >> 32);
    col = static_cast<int>(static_cast<std::uint32_t>(key & 0xffffffffLL));
}

inline int parseColumnWidth(const std::string &width) {
    int value = 0;
    for (char ch: width) {
        value = value * 26 + static_cast<int>(ch - 'A') + 1;
    }
    return value;
}

inline int parseColumnLetters(const std::string &letters) {
    return parseColumnWidth(letters);
}

inline std::pair<int, int> cellFromRc(int row1, const std::string &colLetters) {
    return {row1 - 1, parseColumnLetters(colLetters) - 1};
}

inline std::pair<int, int> parseRef(const std::string &ref) {
    size_t idx = 0;
    while (idx < ref.size() && ref[idx] >= 'A' && ref[idx] <= 'Z') {
        ++idx;
    }
    int row = std::stoi(ref.substr(idx)) - 1;
    int col = parseColumnLetters(ref.substr(0, idx)) - 1;
    return {row, col};
}

using RefWeights = std::unordered_map<long long, int>;

inline RefWeights parseFormula(const std::vector<std::string> &tokens) {
    RefWeights refs;
    for (const std::string &token: tokens) {
        auto colon = token.find(':');
        if (colon == std::string::npos) {
            auto p = parseRef(token);
            refs[cellKey(p.first, p.second)] += 1;
            continue;
        }
        auto start = parseRef(token.substr(0, colon));
        auto end = parseRef(token.substr(colon + 1));
        for (int r = start.first; r <= end.first; ++r) {
            for (int c = start.second; c <= end.second; ++c) {
                refs[cellKey(r, c)] += 1;
            }
        }
    }
    return refs;
}

/** Cached values + weighted reverse dependency graph; O(1) get(). */
class Solution {
public:
    Solution(int height, std::string width)
        : values_(static_cast<size_t>(height),
                  std::vector<int>(static_cast<size_t>(parseColumnWidth(width)), 0)) {
    }

    void set(int row, std::string column, int val) {
        auto target = cellFromRc(row, column);
        long long tkey = cellKey(target.first, target.second);
        int oldValue = values_[static_cast<size_t>(target.first)][static_cast<size_t>(target.second)];
        clearFormula(tkey);
        values_[static_cast<size_t>(target.first)][static_cast<size_t>(target.second)] = val;
        propagate(tkey, val - oldValue);
    }

    int get(int row, std::string column) {
        auto p = cellFromRc(row, column);
        return values_[static_cast<size_t>(p.first)][static_cast<size_t>(p.second)];
    }

    int sum(int row, std::string column, std::vector<std::string> numbers) {
        auto target = cellFromRc(row, column);
        long long tkey = cellKey(target.first, target.second);
        int oldValue = values_[static_cast<size_t>(target.first)][static_cast<size_t>(target.second)];
        clearFormula(tkey);

        RefWeights refs = parseFormula(numbers);
        formulas_[tkey] = std::move(refs);
        for (const auto &[skey, weight]: formulas_[tkey]) {
            dependents_[skey][tkey] += weight;
        }

        int newValue = 0;
        for (const auto &[skey, weight]: formulas_[tkey]) {
            int r = 0;
            int c = 0;
            unpackCell(skey, r, c);
            newValue += values_[static_cast<size_t>(r)][static_cast<size_t>(c)] * weight;
        }
        values_[static_cast<size_t>(target.first)][static_cast<size_t>(target.second)] = newValue;
        propagate(tkey, newValue - oldValue);
        return newValue;
    }

private:
    std::vector<std::vector<int>> values_;
    std::unordered_map<long long, RefWeights> formulas_;
    std::unordered_map<long long, std::unordered_map<long long, int>> dependents_;

    void clearFormula(long long target) {
        auto it = formulas_.find(target);
        if (it == formulas_.end()) {
            return;
        }
        for (const auto &[src, weight]: it->second) {
            auto &depMap = dependents_[src];
            depMap[target] -= weight;
            if (depMap[target] == 0) {
                depMap.erase(target);
            }
            if (depMap.empty()) {
                dependents_.erase(src);
            }
        }
        formulas_.erase(it);
    }

    std::vector<long long> collectAffected(long long start) {
        std::unordered_set<long long> seen;
        std::deque<long long> q;
        q.push_back(start);
        std::vector<long long> order;
        while (!q.empty()) {
            long long src = q.front();
            q.pop_front();
            auto dit = dependents_.find(src);
            if (dit == dependents_.end()) {
                continue;
            }
            for (const auto &[dst, _]: dit->second) {
                if (!seen.insert(dst).second) {
                    continue;
                }
                order.push_back(dst);
                q.push_back(dst);
            }
        }
        return order;
    }

    void propagate(long long start, int delta) {
        if (delta == 0) {
            return;
        }
        if (!dependents_.contains(start)) {
            return;
        }

        std::vector<long long> affected = collectAffected(start);
        if (affected.empty()) {
            return;
        }

        std::unordered_map<long long, int> indegree;
        indegree.reserve(affected.size());
        for (long long cell: affected) {
            indegree[cell] = 0;
        }

        std::vector<long long> sources;
        sources.reserve(affected.size() + 1);
        sources.push_back(start);
        sources.insert(sources.end(), affected.begin(), affected.end());

        for (long long src: sources) {
            auto dit = dependents_.find(src);
            if (dit == dependents_.end()) {
                continue;
            }
            for (const auto &[dst, _]: dit->second) {
                auto jt = indegree.find(dst);
                if (jt != indegree.end()) {
                    ++jt->second;
                }
            }
        }

        std::unordered_map<long long, long long> accumulated;
        accumulated[start] = delta;
        std::deque<long long> queue;
        queue.push_back(start);

        while (!queue.empty()) {
            long long src = queue.front();
            queue.pop_front();
            auto dit = dependents_.find(src);
            if (dit == dependents_.end()) {
                continue;
            }
            long long accSrc = accumulated[src];
            for (const auto &[dst, weight]: dit->second) {
                auto itInd = indegree.find(dst);
                if (itInd == indegree.end()) {
                    continue;
                }
                accumulated[dst] += accSrc * static_cast<long long>(weight);
                --itInd->second;
                if (itInd->second == 0) {
                    int r = 0;
                    int c = 0;
                    unpackCell(dst, r, c);
                    values_[static_cast<size_t>(r)][static_cast<size_t>(c)] +=
                        static_cast<int>(accumulated[dst]);
                    queue.push_back(dst);
                }
            }
        }
    }
};

/** Store formulas and evaluate lazily on get(). */
class Solution2 {
public:
    Solution2(int height, std::string width)
        : values_(static_cast<size_t>(height),
                  std::vector<int>(static_cast<size_t>(parseColumnWidth(width)), 0)) {
    }

    void set(int row, std::string column, int val) {
        auto target = cellFromRc(row, column);
        long long tkey = cellKey(target.first, target.second);
        formulas_.erase(tkey);
        values_[static_cast<size_t>(target.first)][static_cast<size_t>(target.second)] = val;
    }

    int get(int row, std::string column) {
        std::unordered_map<long long, int> memo;
        return evaluate(cellFromRc(row, column), memo);
    }

    int sum(int row, std::string column, std::vector<std::string> numbers) {
        auto target = cellFromRc(row, column);
        long long tkey = cellKey(target.first, target.second);
        formulas_[tkey] = parseFormula(numbers);
        return get(row, column);
    }

private:
    std::vector<std::vector<int>> values_;
    std::unordered_map<long long, RefWeights> formulas_;

    int evaluate(std::pair<int, int> cell, std::unordered_map<long long, int> &memo) {
        long long ck = cellKey(cell.first, cell.second);
        auto mit = memo.find(ck);
        if (mit != memo.end()) {
            return mit->second;
        }
        auto fit = formulas_.find(ck);
        if (fit == formulas_.end()) {
            return values_[static_cast<size_t>(cell.first)][static_cast<size_t>(cell.second)];
        }

        int total = 0;
        for (const auto &[skey, weight]: fit->second) {
            int r = 0;
            int c = 0;
            unpackCell(skey, r, c);
            total += evaluate({r, c}, memo) * weight;
        }
        memo[ck] = total;
        return total;
    }
};

} // namespace lc631

#endif // LEETCODE_EXCELSUMFORMULA_HPP
