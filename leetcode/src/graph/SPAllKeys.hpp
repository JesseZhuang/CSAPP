#ifndef LEETCODE_SPALLKEYS_HPP
#define LEETCODE_SPALLKEYS_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct State {
    size_t r, c;
    int k;

    string toString() {
        return format("r={},c={},k={}", r, c, k);
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) {
        size_t x, y;
        int mk = 0;
        size_t n = grid.size(), m = grid[0].size();
        for (size_t r = 0; r < n; r++) {
            for (size_t c = 0; c < m; c++) {
                char ch = grid[r][c];
                if (ch == '@')
                    x = r, y = c;
                if (islower(ch)) mk = max(mk, ch - 'a' + 1);
            }
        }
        unordered_set < string > vis; // or use string format
        queue<State> q;
        State start{x, y, 0};
        vis.emplace(start.toString());
        q.emplace(start);
        vector<vector<size_t>> dirs = {{0,        1},
                                       {0, SIZE_MAX},
                                       {SIZE_MAX, 0},
                                       {1,        0}};
        int res = 0;
        while (!q.empty()) {
            size_t size = q.size();
            for (size_t i = 0; i < size; i++) {
                auto [cr, cc, ck] = q.front();
                q.pop();
                if (ck == (1 << mk) - 1) return res;
                for (auto d: dirs) {
                    size_t nr = cr + d[0], nc = cc + d[1];
                    int nk = ck;
                    if (nr > n - 1 || nc > m - 1) continue;
                    char ch = grid[nr][nc];
                    if (ch == '#') continue;
                    if (isupper(ch) && (nk & (1 << (ch - 'A'))) == 0) continue;
                    if (islower(ch)) nk |= 1 << (ch - 'a');
                    State state{nr, nc, nk};
                    if (vis.contains(state.toString())) continue;
                    vis.emplace(state.toString());
                    q.emplace(state);
                }
            }
            res++;
        }
        return -1;
    }
};

#endif //LEETCODE_SPALLKEYS_HPP
