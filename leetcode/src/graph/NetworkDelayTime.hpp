#ifndef LEETCODE_NETWORKDELAYTIME_HPP
#define LEETCODE_NETWORKDELAYTIME_HPP

#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution743 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& t : times) {
            graph[t[0]].emplace_back(t[1], t[2]);
        }

        // Dijkstra's algorithm
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        // min-heap: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

#endif // LEETCODE_NETWORKDELAYTIME_HPP
