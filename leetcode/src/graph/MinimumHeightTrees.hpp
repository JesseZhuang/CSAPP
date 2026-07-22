#ifndef LEETCODE_MINIMUMHEIGHTTREES_HPP
#define LEETCODE_MINIMUMHEIGHTTREES_HPP

#include <vector>
#include <queue>

using namespace std;

class MinimumHeightTreesSolution {
public:
    // Time: O(n), Space: O(n)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};

        vector<int> degree(n, 0);               // O(n) space
        vector<vector<int>> adj(n);             // O(n) space

        for (auto& e : edges) {                 // O(n) time
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++) {           // O(n) time
            if (degree[i] == 1) leaves.push(i);
        }

        int remaining = n;
        while (remaining > 2) {                 // O(n) total iterations
            int sz = leaves.size();
            remaining -= sz;
            for (int i = 0; i < sz; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adj[leaf]) {
                    if (--degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};

#endif //LEETCODE_MINIMUMHEIGHTTREES_HPP
