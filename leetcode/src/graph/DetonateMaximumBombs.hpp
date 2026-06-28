#ifndef LEETCODE_DETONATEMAXIMUMBOMBS_HPP
#define LEETCODE_DETONATEMAXIMUMBOMBS_HPP

#include <vector>
#include <queue>
#include <functional>

using namespace std;

// LeetCode 2101: Detonate the Maximum Bombs
// Time: O(n^3) — for each of n bombs, BFS/DFS visits up to n nodes with n edges each
// Space: O(n^2) — adjacency list storage

class DetonateMaximumBombs {
public:
    // BFS approach
    static int maximumDetonationBFS(vector<vector<int>> &bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r)
                    adj[i].push_back(j);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int count = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                count++;
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            res = max(res, count);
        }
        return res;
    }

    // DFS approach
    static int maximumDetonationDFS(vector<vector<int>> &bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r)
                    adj[i].push_back(j);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int count = 0;
            function<void(int)> dfs = [&](int u) {
                visited[u] = true;
                count++;
                for (int v : adj[u]) {
                    if (!visited[v]) dfs(v);
                }
            };
            dfs(i);
            res = max(res, count);
        }
        return res;
    }
};

#endif //LEETCODE_DETONATEMAXIMUMBOMBS_HPP
