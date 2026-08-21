#ifndef LEETCODE_NUMBEROFCONNECTEDCOMPONENTS_HPP
#define LEETCODE_NUMBEROFCONNECTEDCOMPONENTS_HPP

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // Union-Find with path compression + union by rank.
    // Time: O(n + e * alpha(n)) — process each edge with near-constant union/find.
    // Space: O(n) — parent and rank arrays.
    static int countComponentsUF(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);   // O(n) space
        vector<int> rank(n, 0);  // O(n) space for union by rank
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
        int components = n; // start with n isolated components

        for (auto& e : edges) { // O(e) iterations
            int ri = find(parent, e[0]); // amortized O(alpha(n))
            int rj = find(parent, e[1]);
            if (ri != rj) {
                unite(parent, rank, ri, rj);
                components--; // merging two components
            }
        }
        return components;
    }

    // DFS iterative: build adjacency list, then count components.
    // Time: O(n + e) — build adj list + visit every node and edge once.
    // Space: O(n + e) — adjacency list storage.
    static int countComponentsDFS(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); // O(n + 2e) space for adjacency list
        for (auto& e : edges) { // O(e) — build adjacency list
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false); // O(n) space
        int components = 0;

        for (int i = 0; i < n; i++) { // O(n) — check each node
            if (visited[i]) continue;
            components++;
            // DFS using stack — visits each edge at most twice total across all calls
            vector<int> stk = {i};
            visited[i] = true;
            while (!stk.empty()) {
                int node = stk.back();
                stk.pop_back();
                for (int nb : adj[node]) { // O(degree) per node
                    if (!visited[nb]) {
                        visited[nb] = true;
                        stk.push_back(nb);
                    }
                }
            }
        }
        return components;
    }

private:
    // Find with path compression (halving) — amortized O(alpha(n)).
    static int find(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    // Union by rank — keeps tree balanced.
    static void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
};

#endif //LEETCODE_NUMBEROFCONNECTEDCOMPONENTS_HPP
