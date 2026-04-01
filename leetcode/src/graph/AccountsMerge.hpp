#ifndef LEETCODE_ACCOUNTSMERGE_HPP
#define LEETCODE_ACCOUNTSMERGE_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

// Namespaced so `class Solution` does not ODR-collide with other problem headers
// in the unified LeetCode_test binary (destructor symbols would merge incorrectly).
namespace lc721 {

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        parent.clear();
        rank_.clear();
        unordered_map<string, string> emailToName;
        for (auto &acc: accounts) {
            for (size_t i = 1; i < acc.size(); ++i) {
                add(acc[i]);
                emailToName.emplace(acc[i], acc[0]);
                union_(acc[1], acc[i]);
            }
        }
        unordered_map<string, vector<string>> groups;
        for (auto &[email, _]: parent) {
            groups[find(email)].push_back(email);
        }
        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto &[root, emails]: groups) {
            sort(emails.begin(), emails.end());
            vector<string> row;
            row.push_back(emailToName[root]);
            row.insert(row.end(), emails.begin(), emails.end());
            res.push_back(std::move(row));
        }
        return res;
    }

private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank_;

    void add(const string &e) {
        if (!parent.contains(e)) {
            parent[e] = e;
            rank_[e] = 0;
        }
    }

    string find(string x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void union_(string a, string b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            ++rank_[a];
    }
};

class Solution2 {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, unordered_set<string>> graph;
        unordered_map<string, string> emailToName;
        for (auto &acc: accounts) {
            for (size_t i = 1; i < acc.size(); ++i) {
                emailToName.emplace(acc[i], acc[0]);
                graph[acc[1]].insert(acc[i]);
                graph[acc[i]].insert(acc[1]);
            }
        }
        unordered_set<string> visited;
        vector<vector<string>> res;
        for (auto &[email, _]: graph) {
            if (visited.contains(email))
                continue;
            vector<string> comp;
            dfs(graph, email, visited, comp);
            sort(comp.begin(), comp.end());
            vector<string> row;
            row.push_back(emailToName[email]);
            row.insert(row.end(), comp.begin(), comp.end());
            res.push_back(std::move(row));
        }
        return res;
    }

private:
    static void dfs(const unordered_map<string, unordered_set<string>> &graph,
                    const string &e,
                    unordered_set<string> &visited,
                    vector<string> &comp) {
        visited.insert(e);
        comp.push_back(e);
        auto it = graph.find(e);
        if (it == graph.end())
            return;
        for (const string &n: it->second) {
            if (!visited.contains(n))
                dfs(graph, n, visited, comp);
        }
    }
};

} // namespace lc721

#endif // LEETCODE_ACCOUNTSMERGE_HPP
