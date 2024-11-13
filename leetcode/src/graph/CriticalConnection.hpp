#ifndef LEETCODE_CRITICALCONNECTION_HPP
#define LEETCODE_CRITICALCONNECTION_HPP

#include <vector>

using namespace std;

class Solution {
    vector<int> ranks;
    vector<vector<int>> res;
    vector<vector<int>> adj;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        adj.resize(n);
        ranks.resize(n);
        for (auto &e: connections)
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        for (int v = 0; v < n; v++)
            dfs(0, v, 1);
        return res;
    }

    void dfs(int p, int v, int rank) {
        if (ranks[v] != 0) return;
        ranks[v] = rank;
        int r = 0;
        for (int w: adj[v]) {
            if (w == p) continue;
            dfs(v, w, rank + 1);
            ranks[v] = min(ranks[v], ranks[w]);
            if (rank < ranks[w]) res.emplace_back(initializer_list<int>{v, w});
        }
    }
};

#endif //LEETCODE_CRITICALCONNECTION_HPP
