#pragma once
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution841 {
public:
    // DFS iterative. O(N+E) time, O(N) space.
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        stack<int> st;
        st.push(0);
        visited.insert(0);
        while (!st.empty()) {
            int room = st.top();
            st.pop();
            for (int key : rooms[room]) {
                if (visited.find(key) == visited.end()) {
                    visited.insert(key);
                    st.push(key);
                }
            }
        }
        return (int)visited.size() == n;
    }

    // BFS. O(N+E) time, O(N) space.
    bool canVisitAllRoomsBFS(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            for (int key : rooms[room]) {
                if (visited.find(key) == visited.end()) {
                    visited.insert(key);
                    q.push(key);
                }
            }
        }
        return (int)visited.size() == n;
    }
};
