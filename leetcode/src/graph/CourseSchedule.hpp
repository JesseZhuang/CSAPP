#ifndef LEETCODE_COURSESCHEDULE_HPP
#define LEETCODE_COURSESCHEDULE_HPP

#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution207 {
public:
    // DFS cycle detection using color array (WHITE=0, GRAY=1, BLACK=2).
    // O(V+E) time, O(V+E) space.
    bool canFinishDFS(int numCourses, vector<vector<int>> &prerequisites) {
        enum Color { WHITE, GRAY, BLACK };
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<Color> color(n, WHITE);

        // O(E) — build adjacency list
        for (auto &e : prerequisites) adj[e[1]].emplace_back(e[0]);

        bool hasCycle = false;
        function<void(int)> dfs = [&](int u) {
            color[u] = GRAY;
            // O(deg(u)) — visit all neighbors
            for (int v : adj[u]) {
                if (color[v] == GRAY) { hasCycle = true; return; }
                if (color[v] == WHITE) dfs(v);
                if (hasCycle) return;
            }
            color[u] = BLACK;
        };

        // O(V) — ensure all components are visited
        for (int i = 0; i < n && !hasCycle; i++)
            if (color[i] == WHITE) dfs(i);

        return !hasCycle;
    }

    // BFS topological sort (Kahn's algorithm) with in-degree array.
    // O(V+E) time, O(V+E) space.
    bool canFinishBFS(int numCourses, vector<vector<int>> &prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // O(E) — build adjacency list and in-degree counts
        for (auto &e : prerequisites) {
            adj[e[1]].emplace_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;
        // O(V) — seed queue with zero in-degree nodes
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) q.push(i);

        int visited = 0;
        // O(V+E) — process each node and relax edges
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;
            for (int v : adj[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }

        return visited == n;
    }
};

#endif //LEETCODE_COURSESCHEDULE_HPP
