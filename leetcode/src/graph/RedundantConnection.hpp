#ifndef LEETCODE_REDUNDANTCONNECTION_HPP
#define LEETCODE_REDUNDANTCONNECTION_HPP

#include <vector>
#include <numeric>
#include <unordered_set>
#include <functional>

using namespace std;

class RedundantConnectionSolution {
public:
    // Union Find with path compression and union by rank.
    // Time: O(n * alpha(n)) ~= O(n), Space: O(n).
    vector<int> findRedundantConnectionUF(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);

        for (auto &e: edges) {
            int px = find(parent, e[0]), py = find(parent, e[1]);
            if (px == py) return e; // already connected — redundant edge
            if (rank[px] < rank[py]) swap(px, py); // union by rank
            parent[py] = px;
            if (rank[px] == rank[py]) rank[px]++;
        }
        return {};
    }

    // DFS cycle detection. O(n) time, O(n) space.
    vector<int> findRedundantConnectionDFS(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (auto &e: edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }

        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        int cycleStart = -1;

        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (int v: adj[u]) {
                if (!visited[v]) {
                    parent[v] = u;
                    dfs(v);
                } else if (v != parent[u] && cycleStart == -1) {
                    cycleStart = v;
                    parent[v] = u;
                }
            }
        };
        dfs(0);

        unordered_set<int> cycleNodes;
        int node = cycleStart;
        do {
            cycleNodes.insert(node);
            node = parent[node];
        } while (node != cycleStart);

        for (int i = n - 1; i >= 0; i--) {
            if (cycleNodes.count(edges[i][0] - 1) && cycleNodes.count(edges[i][1] - 1))
                return edges[i];
        }
        return {};
    }

private:
    int find(vector<int> &parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path compression
            x = parent[x];
        }
        return x;
    }
};

#endif //LEETCODE_REDUNDANTCONNECTION_HPP
