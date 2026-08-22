#ifndef LEETCODE_ISGRAPHBIPARTITE_HPP
#define LEETCODE_ISGRAPHBIPARTITE_HPP

#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class IsGraphBipartiteSolution {
public:
    // BFS coloring approach.
    // Time: O(V + E), Space: O(V)
    bool isBipartiteBFS(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0/1 = two colors

        for (int i = 0; i < n; i++) { // handle disconnected components
            if (color[i] != -1) continue;
            queue<int> q;
            q.push(i);
            color[i] = 0; // assign initial color
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) { // O(E) total across all BFS
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; // assign opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // same color on both ends — not bipartite
                    }
                }
            }
        }
        return true;
    }

    // Union-Find approach.
    // For each node, union all its neighbors; if node is in same set as a neighbor, not bipartite.
    // Time: O(V * alpha(V) + E), Space: O(V)
    bool isBipartiteUF(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                if (find(parent, u) == find(parent, v)) {
                    return false; // u and v in same set — odd cycle detected
                }
                unite(parent, rank, graph[u][0], v); // union all neighbors together
            }
        }
        return true;
    }

private:
    int find(vector<int> &parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path compression (halving)
            x = parent[x];
        }
        return x;
    }

    void unite(vector<int> &parent, vector<int> &rank, int x, int y) {
        int px = find(parent, x), py = find(parent, y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py); // union by rank
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};

#endif //LEETCODE_ISGRAPHBIPARTITE_HPP
