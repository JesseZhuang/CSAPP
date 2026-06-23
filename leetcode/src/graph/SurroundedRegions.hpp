#ifndef LEETCODE_SURROUNDEDREGIONS_HPP
#define LEETCODE_SURROUNDEDREGIONS_HPP

#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    // BFS from boundary: mark border-connected 'O' cells as safe, then flip the rest.
    // Time: O(m*n), Space: O(m*n).
    void solveBfs(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        queue<pair<int, int>> q;
        // Enqueue all border 'O' cells
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') { board[i][0] = '#'; q.push({i, 0}); }
            if (board[i][n - 1] == 'O') { board[i][n - 1] = '#'; q.push({i, n - 1}); }
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O') { board[0][j] = '#'; q.push({0, j}); }
            if (board[m - 1][j] == 'O') { board[m - 1][j] = '#'; q.push({m - 1, j}); }
        }

        int dirs[] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d], nc = c + dirs[d + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        // Restore '#' -> 'O', flip remaining 'O' -> 'X'
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
    }

    // Union-Find approach: union border-connected 'O' cells with a virtual node.
    // Time: O(m*n * alpha(m*n)), Space: O(m*n).
    void solveUF(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        int total = m * n;
        int dummy = total; // virtual node for border-connected cells

        vector<int> par(total + 1), rnk(total + 1, 0);
        for (int i = 0; i <= total; i++) par[i] = i;

        function<int(int)> find = [&](int x) -> int {
            while (par[x] != x) {
                par[x] = par[par[x]];
                x = par[x];
            }
            return x;
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (rnk[a] < rnk[b]) swap(a, b);
            par[b] = a;
            if (rnk[a] == rnk[b]) rnk[a]++;
        };

        auto idx = [&](int i, int j) { return i * n + j; };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'O') continue;
                // If on border, union with dummy
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    unite(idx(i, j), dummy);
                // Union with right and down neighbors
                if (i + 1 < m && board[i + 1][j] == 'O')
                    unite(idx(i, j), idx(i + 1, j));
                if (j + 1 < n && board[i][j + 1] == 'O')
                    unite(idx(i, j), idx(i, j + 1));
            }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O' && find(idx(i, j)) != find(dummy))
                    board[i][j] = 'X';
    }
};

#endif //LEETCODE_SURROUNDEDREGIONS_HPP
