#ifndef PARALLELCOURSESIII_HPP
#define PARALLELCOURSESIII_HPP

#include <functional>
#include <vector>

using namespace std;

// LeetCode
class Solution {
public:
    int minimumTime(int n, vector<vector<int> > &relations, vector<int> &time) {
        vector<int> cache(n + 1, {-1});
        vector adj(n + 1, vector<int>(0));
        for (vector<int> &e: relations)
            adj[e[0]].emplace_back(e[1]);
        function<void(int)> dfs = [&](int v) {
            if (cache[v] != -1) return;
            cache[v] = 0;
            for (int w: adj[v]) {
                dfs(w);
                cache[v] = max(cache[v], cache[w]);
            }
            cache[v] += time[v - 1];
        };
        for (int i = 1; i <= n; i++) dfs(i);
        return *max_element(cache.begin(), cache.end());
    }
};
#endif //PARALLELCOURSESIII_HPP
