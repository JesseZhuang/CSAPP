#ifndef LEETCODE_EVENTUALSAFESTATES_HPP
#define LEETCODE_EVENTUALSAFESTATES_HPP

#include <vector>
#include <queue>

using namespace std;

class Solution802 {
public:
    // DFS 3-coloring: UNVISITED=0, VISITING=1, SAFE=2.
    // O(V+E) time, O(V) space.
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n, 0); // O(V) space — color array

        // Returns true if node u is safe (all paths lead to terminal).
        function<bool(int)> dfs = [&](int u) -> bool {
            if (color[u] != 0) return color[u] == 2; // O(1) — already resolved
            color[u] = 1; // mark visiting
            // O(deg(u)) — check all neighbors
            for (int v : graph[u]) {
                if (!dfs(v)) return false; // cycle or reaches cycle
            }
            color[u] = 2; // O(1) — mark safe
            return true;
        };

        vector<int> res;
        // O(V+E) — each node/edge visited at most once
        for (int i = 0; i < n; i++)
            if (dfs(i)) res.push_back(i);

        return res; // already sorted since we iterate 0..n-1
    }

    // Reverse graph + topological sort BFS (Kahn's from terminal nodes).
    // O(V+E) time, O(V+E) space.
    vector<int> eventualSafeNodesBFS(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<int>> radj(n); // O(V+E) space — reverse adjacency list
        vector<int> outdegree(n, 0); // O(V) space — original out-degree

        // O(V+E) — build reverse graph and compute out-degrees
        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();
            for (int v : graph[u]) {
                radj[v].push_back(u); // reverse edge v -> u
            }
        }

        queue<int> q;
        // O(V) — seed queue with terminal nodes (out-degree 0)
        for (int i = 0; i < n; i++)
            if (outdegree[i] == 0) q.push(i);

        vector<bool> safe(n, false); // O(V) space
        // O(V+E) — BFS propagation through reverse edges
        while (!q.empty()) {
            int u = q.front(); q.pop();
            safe[u] = true;
            for (int v : radj[u]) {
                if (--outdegree[v] == 0) q.push(v); // all successors safe
            }
        }

        vector<int> res;
        // O(V) — collect safe nodes in sorted order
        for (int i = 0; i < n; i++)
            if (safe[i]) res.push_back(i);

        return res;
    }
};

#endif //LEETCODE_EVENTUALSAFESTATES_HPP
