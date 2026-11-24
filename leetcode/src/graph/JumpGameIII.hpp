#pragma once

#include <initializer_list>
#include <queue>
#include <stack>
#include <vector>

class Solution1306BFS {
public:
    // BFS. O(n) time and O(n) space since each index is enqueued at most once.
    bool canReach(std::vector<int>& arr, int start) {
        const int n = static_cast<int>(arr.size());
        std::vector<bool> visited(n);
        std::queue<int> pending;
        visited[start] = true;
        pending.push(start);

        while (!pending.empty()) {
            const int index = pending.front();
            pending.pop();
            const int jump = arr[index];
            if (jump == 0) return true;

            for (int next : {index + jump, index - jump}) {
                if (0 <= next && next < n && !visited[next]) {
                    visited[next] = true;
                    pending.push(next);
                }
            }
        }
        return false;
    }
};

class Solution1306DFS {
public:
    // Iterative DFS. O(n) time and O(n) space since each index is pushed at most once.
    bool canReach(std::vector<int>& arr, int start) {
        const int n = static_cast<int>(arr.size());
        std::vector<bool> visited(n);
        std::stack<int> pending;
        visited[start] = true;
        pending.push(start);

        while (!pending.empty()) {
            const int index = pending.top();
            pending.pop();
            const int jump = arr[index];
            if (jump == 0) return true;

            for (int next : {index + jump, index - jump}) {
                if (0 <= next && next < n && !visited[next]) {
                    visited[next] = true;
                    pending.push(next);
                }
            }
        }
        return false;
    }
};
