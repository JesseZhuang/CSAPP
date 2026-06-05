#ifndef LEETCODE_CHEAPESTFLIGHTSWITHINKSTOPS_HPP
#define LEETCODE_CHEAPESTFLIGHTSWITHINKSTOPS_HPP

#include <vector>
#include <queue>
#include <climits>

using namespace std;

/// Bellman-Ford variant: relax all edges up to k+1 times.
/// Time O((k+1) * E), Space O(n).
class Solution787BF {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) { // O(k+1) rounds
            vector<int> tmp(prices);
            for (auto& f : flights) { // O(E) edges per round
                if (prices[f[0]] != INT_MAX && prices[f[0]] + f[2] < tmp[f[1]]) {
                    tmp[f[1]] = prices[f[0]] + f[2];
                }
            }
            prices = tmp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

/// BFS with pruning: level-order BFS where level = number of stops.
/// Time O((k+1) * E), Space O(n + E).
class Solution787BFS {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& f : flights) graph[f[0]].emplace_back(f[1], f[2]);

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, int>> q;
        q.emplace(src, 0);
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) { // O(level width)
                auto [node, cost] = q.front();
                q.pop();
                for (auto& [nei, w] : graph[node]) { // O(edges from node)
                    int newCost = cost + w;
                    if (newCost < dist[nei]) {
                        dist[nei] = newCost;
                        q.emplace(nei, newCost);
                    }
                }
            }
            stops++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

#endif // LEETCODE_CHEAPESTFLIGHTSWITHINKSTOPS_HPP
