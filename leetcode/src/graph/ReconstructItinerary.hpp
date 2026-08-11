#ifndef LEETCODE_RECONSTRUCTITINERARY_HPP
#define LEETCODE_RECONSTRUCTITINERARY_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

class Solution332 {
public:
    // Hierholzer's algorithm (recursive DFS).
    // O(E log E) time — each edge visited once, priority_queue gives lexicographic order.
    // O(E) space — adjacency list + recursion stack.
    static vector<string> findItinerary(vector<vector<string>>& tickets) {
        // O(E log E) — build adjacency with min-heap for lexicographic order
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& t : tickets) {
            graph[t[0]].push(t[1]);
        }

        vector<string> route;
        function<void(const string&)> dfs = [&](const string& airport) {
            while (!graph[airport].empty()) {
                string next = graph[airport].top(); // O(log E)
                graph[airport].pop();
                dfs(next);
            }
            route.push_back(airport); // O(1) amortized
        };

        dfs("JFK");
        reverse(route.begin(), route.end()); // O(E)
        return route;
    }

    // Hierholzer's algorithm (iterative stack).
    // O(E log E) time, O(E) space.
    static vector<string> findItinerary2(vector<vector<string>>& tickets) {
        // O(E log E) — build adjacency with min-heap
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& t : tickets) {
            graph[t[0]].push(t[1]);
        }

        vector<string> route;
        stack<string> stk;
        stk.push("JFK");

        while (!stk.empty()) {
            string top = stk.top();
            if (!graph[top].empty()) {
                string next = graph[top].top(); // O(log E)
                graph[top].pop();
                stk.push(next);
            } else {
                route.push_back(top); // O(1) amortized
                stk.pop();
            }
        }

        reverse(route.begin(), route.end()); // O(E)
        return route;
    }
};

#endif // LEETCODE_RECONSTRUCTITINERARY_HPP
