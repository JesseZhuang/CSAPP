#ifndef SHOPPINGOFFERS_HPP
#define SHOPPINGOFFERS_HPP

#include <algorithm>
#include <functional>
#include <unordered_map>
#include <vector>

using namespace std;

struct VectorHash {
    size_t operator()(const vector<int> &v) const {
        size_t seed = v.size();
        for (auto x : v) seed ^= hash<int>()(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

class Solution {
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                       vector<int> &needs) {
        int n = static_cast<int>(price.size());
        vector<vector<int>> filt;
        for (const auto &s : special) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += s[i] * price[i];
            }
            if (sum > s.back()) {
                filt.push_back(s);
            }
        }
        unordered_map<vector<int>, int, VectorHash> memo;
        function<int(const vector<int> &)> dfs = [&](const vector<int> &cur) -> int {
            if (auto it = memo.find(cur); it != memo.end()) {
                return it->second;
            }
            int res = 0;
            for (int i = 0; i < n; ++i) {
                res += cur[i] * price[i];
            }
            for (const auto &off : filt) {
                vector<int> updated(n);
                for (int i = 0; i < n; ++i) updated[i] = cur[i] - off[i];
                if (all_of(updated.begin(), updated.end(), [](int v) { return v >= 0; })) {
                    res = min(res, off.back() + dfs(updated));
                }
            }
            memo[cur] = res;
            return res;
        };
        return dfs(needs);
    }

    int shoppingOffers2(vector<int> &price, vector<vector<int>> &special,
                        vector<int> &needs) {
        int n = static_cast<int>(price.size());
        vector<vector<int>> filt;
        for (const auto &s : special) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += s[i] * price[i];
            }
            if (sum > s.back()) {
                filt.push_back(s);
            }
        }
        function<int(int, vector<int>)> dfs = [&](int idx, vector<int> nd) -> int {
            if (idx == static_cast<int>(filt.size())) {
                int s = 0;
                for (int i = 0; i < n; ++i) {
                    s += nd[i] * price[i];
                }
                return s;
            }
            int res = dfs(idx + 1, nd);
            vector<int> updated = nd;
            int times = 0;
            while (true) {
                for (int i = 0; i < n; ++i) {
                    updated[i] -= filt[idx][i];
                }
                if (any_of(updated.begin(), updated.end(),
                            [](int u) { return u < 0; })) {
                    break;
                }
                ++times;
                res = min(res, filt[idx].back() * times + dfs(idx + 1, updated));
            }
            return res;
        };
        return dfs(0, needs);
    }
};

#endif // SHOPPINGOFFERS_HPP
