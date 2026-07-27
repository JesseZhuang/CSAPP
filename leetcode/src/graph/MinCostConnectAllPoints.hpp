#ifndef LEETCODE_MINCOSTCONNECTALLPOINTS_HPP
#define LEETCODE_MINCOSTCONNECTALLPOINTS_HPP

#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

namespace lc1584 {

// Prim's algorithm with min-heap priority queue
// Time: O(n^2 log n), Space: O(n^2)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;

        // min-heap: (cost, node index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> inMST(n, false);
        pq.emplace(0, 0);
        int totalCost = 0;
        int edgesUsed = 0;

        // O(n^2 log n): each of n nodes can add up to n-1 edges to the heap
        while (edgesUsed < n) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;
            totalCost += cost;
            edgesUsed++;

            // O(n) per node: add all edges from u to non-MST nodes
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0])
                             + abs(points[u][1] - points[v][1]);
                    pq.emplace(dist, v);
                }
            }
        }
        return totalCost;
    }
};

// Kruskal's algorithm with union-find (rank + path halving)
// Time: O(n^2 log n), Space: O(n^2)
class Solution2 {
    vector<int> parent, rank_;

    int find(int x) {
        // Path halving: point to grandparent
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        // Union by rank
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;

        // O(n^2): generate all edges
        vector<array<int, 3>> edges; // {cost, u, v}
        edges.reserve(n * (n - 1) / 2);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0])
                         + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        // O(n^2 log n): sort all edges by cost
        sort(edges.begin(), edges.end());

        // Initialize union-find
        parent.resize(n);
        rank_.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        int totalCost = 0;
        int edgesUsed = 0;

        // O(n^2 * alpha(n)): iterate edges, nearly linear per union/find
        for (auto& [cost, u, v] : edges) {
            if (unite(u, v)) {
                totalCost += cost;
                if (++edgesUsed == n - 1) break;
            }
        }
        return totalCost;
    }
};

} // namespace lc1584

#endif // LEETCODE_MINCOSTCONNECTALLPOINTS_HPP
