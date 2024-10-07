#ifndef REMOVEMETHODS_HPP
#define REMOVEMETHODS_HPP

#include <queue>
#include <vector>

using namespace std;

// leet code 3310, medium, weekly 418 Q2
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int> > &invocations) {
        vector<vector<int> > adj(n), radj(n);
        for (auto v: invocations) {
            int x = v[0], y = v[1];
            adj[x].push_back(y);
            radj[y].push_back(x);
        }
        vector<bool> mark(n);
        queue<int> q;
        q.push(k); // mark all suspicious methods
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            mark[u] = true;
            for (int v: adj[u]) {
                if (!mark[v]) {
                    mark[v] = true;
                    q.push(v);
                }
            }
        }
        bool good = true;
        for (int v = 0; v < n; ++v)
            for (int w: adj[v])
                if (!mark[v] and mark[w]) good = false;

        vector<int> res; // LeeCode does not support ranges::to
        if (!good) for (int i = 0; i < n; i++) res.push_back(i);
        else for (int i = 0; i < n; ++i) if (!mark[i]) res.push_back(i);
        return res;
    }
};


#endif //REMOVEMETHODS_HPP
