#ifndef LEETCODE_PATHWITHMAXPROBABILITY_HPP
#define LEETCODE_PATHWITHMAXPROBABILITY_HPP

#include <vector>
#include <queue>

using namespace std;

// Solution 1: Modified Dijkstra with max-heap. O((V+E)logV) time, O(V+E) space.
class Solution1514 {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb,
                          int start_node, int end_node) {
        // Build adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // Max-heap: (probability, node)
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start_node);

        // O((V+E)logV) — each node extracted at most once, each edge relaxed once
        while (!pq.empty()) {
            auto [p, u] = pq.top();
            pq.pop();
            if (u == end_node) return p;
            if (p < prob[u]) continue; // stale entry
            // O(degree(u)) per node — total O(E) relaxations across all iterations
            for (auto& [v, w] : graph[u]) {
                double newProb = p * w;
                if (newProb > prob[v]) {
                    prob[v] = newProb;
                    pq.emplace(newProb, v); // O(logV) heap push
                }
            }
        }
        return 0.0;
    }
};

// Solution 2: Bellman-Ford relaxation. O(V*E) time, O(V) space.
class Solution1514BF {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb,
                          int start_node, int end_node) {
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;

        // O(V) iterations in the worst case
        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;
            // O(E) edge relaxations per iteration
            for (int j = 0; j < (int)edges.size(); ++j) {
                int u = edges[j][0], v = edges[j][1];
                double w = succProb[j];
                if (prob[u] * w > prob[v]) {
                    prob[v] = prob[u] * w;
                    updated = true;
                }
                if (prob[v] * w > prob[u]) {
                    prob[u] = prob[v] * w;
                    updated = true;
                }
            }
            if (!updated) break; // early termination
        }
        return prob[end_node];
    }
};

#endif // LEETCODE_PATHWITHMAXPROBABILITY_HPP
