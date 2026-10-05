#ifndef LEETCODE_SHORTESTPATHALTERNATINGCOLORS_HPP
#define LEETCODE_SHORTESTPATHALTERNATINGCOLORS_HPP

#include <queue>
#include <tuple>
#include <vector>

using namespace std;

// LeetCode 1129 - Shortest Path with Alternating Colors
class Solution1129 {
public:
    // BFS over (node, previous edge color) states: O(n + m) time, O(n + m) space.
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        constexpr int RED = 0;
        constexpr int BLUE = 1;
        constexpr int NONE = 2;

        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
        for (const auto& edge : redEdges) {
            graph[RED][edge[0]].push_back(edge[1]);
        }
        for (const auto& edge : blueEdges) {
            graph[BLUE][edge[0]].push_back(edge[1]);
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        queue<tuple<int, int, int>> q;
        q.push({0, NONE, 0});
        answer[0] = 0;

        while (!q.empty()) {
            auto [node, previousColor, distance] = q.front();
            q.pop();

            for (int color = RED; color <= BLUE; color++) {
                if (color == previousColor) {
                    continue;
                }
                for (int next : graph[color][node]) {
                    if (visited[next][color]) {
                        continue;
                    }
                    visited[next][color] = true;
                    if (answer[next] == -1) {
                        answer[next] = distance + 1;
                    }
                    q.push({next, color, distance + 1});
                }
            }
        }

        return answer;
    }
};

#endif //LEETCODE_SHORTESTPATHALTERNATINGCOLORS_HPP
