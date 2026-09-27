#ifndef LEETCODE_SMALLESTSTRINGWITHSWAPS_HPP
#define LEETCODE_SMALLESTSTRINGWITHSWAPS_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

namespace lc1202 {

// Solution 1: Union-Find with rank + path compression
// O(n·α(n) + n·log(n)) time, O(n) space
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int n = static_cast<int>(s.size());
        parent.resize(n);
        rank_.resize(n, 0);
        for (int i = 0; i < n; ++i)      // O(n) init
            parent[i] = i;

        for (auto &p : pairs)             // O(E·α(n)) union operations
            union_(p[0], p[1]);

        // Group indices by root
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i)       // O(n·α(n))
            groups[find(i)].push_back(i);

        // Sort characters within each component and place back
        for (auto &[root, indices] : groups) {
            string chars;
            chars.reserve(indices.size());
            for (int i : indices)
                chars += s[i];
            sort(chars.begin(), chars.end());   // O(k·log(k)) per component
            for (size_t j = 0; j < indices.size(); ++j)
                s[indices[j]] = chars[j];
        }
        return s;
    }

private:
    vector<int> parent;
    vector<int> rank_;

    int find(int x) {
        while (parent[x] != x) {          // path compression (halving)
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void union_(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank_[a] < rank_[b])           // union by rank
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            ++rank_[a];
    }
};

// Solution 2: DFS connected components
// O(n·log(n) + E) time, O(n + E) space
class Solution2 {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int n = static_cast<int>(s.size());

        // Build adjacency list — O(E) time & space
        vector<vector<int>> adj(n);
        for (auto &p : pairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        // DFS to find connected components
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {     // O(n + E) total across all DFS calls
            if (visited[i]) continue;
            vector<int> comp;
            dfs(adj, i, visited, comp);

            // Sort indices and corresponding characters — O(k·log(k))
            string chars;
            chars.reserve(comp.size());
            for (int idx : comp)
                chars += s[idx];
            sort(comp.begin(), comp.end());
            sort(chars.begin(), chars.end());
            for (size_t j = 0; j < comp.size(); ++j)
                s[comp[j]] = chars[j];
        }
        return s;
    }

private:
    static void dfs(const vector<vector<int>> &adj, int u,
                     vector<bool> &visited, vector<int> &comp) {
        visited[u] = true;
        comp.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v])
                dfs(adj, v, visited, comp);
        }
    }
};

} // namespace lc1202

#endif // LEETCODE_SMALLESTSTRINGWITHSWAPS_HPP
