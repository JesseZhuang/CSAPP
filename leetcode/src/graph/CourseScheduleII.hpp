#ifndef LEETCODE_COURSESCHEDULEII_HPP
#define LEETCODE_COURSESCHEDULEII_HPP

#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        int n = numCourses;
        vector<int> res, marked(n, false), onStack(n, false);
        vector<vector<int>> adj(n);
        bool cycle = false;
        for (auto e: prerequisites) adj[e[1]].emplace_back(e[0]);
        function<void(int)> dfs = [&](int v) {
            if (marked[v]) return;
            onStack[v] = true, marked[v] = true;
            for (int w: adj[v]) {
                if (onStack[w]) cycle = true;
                else dfs(w);
            }
            onStack[v] = false;
            res.emplace_back(v);
        };
        for (int i = 0; i < n; i++)
            if (!cycle) dfs(i); else return {};
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODE_COURSESCHEDULEII_HPP
