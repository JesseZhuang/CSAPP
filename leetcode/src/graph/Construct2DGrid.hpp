#ifndef CONSTRUCT2DGRID_HPP
#define CONSTRUCT2DGRID_HPP

#include <vector>
#include <queue>

using namespace std;

// LeetCode 3311, hard, weekly 418 Q3
class Solution {
public:
    vector<vector<int> > constructGridLayout(int n, vector<vector<int> > &edges) {
        vector<vector<int> > adj(n);
        for (auto v: edges) {
            int x = v[0], y = v[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int src = 0;
        for (int i = 0; i < n; ++i)
            if (adj[i].size() < adj[src].size())
                src = i;
        vector<int> dist(n, n + 5);
        queue<int> qu;
        qu.push(src);
        dist[src] = 0;
        vector<vector<int> > who(n + 5);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            who[dist[u]].push_back(u);
            for (int v: adj[u]) {
                if (dist[v] > 1 + dist[u]) {
                    dist[v] = 1 + dist[u];
                    qu.push(v);
                }
            }
        }

        vector<array<int, 2> > loc(n);
        loc[src] = {0, 0};
        loc[who[1][0]] = {0, 1};
        if (who[1].size() > 1) loc[who[1][1]] = {1, 0};

        int r = 0, c = 0;
        for (int d = 2; d <= n; ++d) {
            for (int x: who[d]) {
                int ct = 0, mx = 0, my = 0;
                for (int y: adj[x]) {
                    if (dist[y] < dist[x]) {
                        auto [X, Y] = loc[y];
                        mx = max(mx, X);
                        my = max(my, Y);
                        ++ct;
                    }
                }

                if (ct == 2) loc[x] = {mx, my};
                else {
                    if (mx == 0) loc[x] = {0, my + 1};
                    else loc[x] = {mx + 1, 0};
                }
            }
        }

        for (auto [x, y]: loc) {
            r = max(r, x);
            c = max(c, y);
        }

        vector<vector<int> > ans(r + 1, vector<int>(c + 1));
        for (int i = 0; i < n; ++i) {
            auto [x, y] = loc[i];
            ans[x][y] = i;
        }
        return ans;
    }
};


#endif //CONSTRUCT2DGRID_HPP
