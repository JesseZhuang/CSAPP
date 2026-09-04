#ifndef LEETCODE_GAMEOFLIFE_HPP
#define LEETCODE_GAMEOFLIFE_HPP

#include <vector>

using namespace std;

// Solution 1: In-place State Encoding - Time O(mn), Space O(1)
// Use the 2nd bit to store the next state while preserving the current state in the 1st bit.
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        // O(mn) first pass: compute next state and store in 2nd bit
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;                           // O(1) neighbor count
                for (auto& d : dirs) {                  // O(8) = O(1) check all 8 neighbors
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                        live += board[ni][nj] & 1;      // read current state from 1st bit
                }
                // Cell lives if: exactly 3 neighbors, or alive with exactly 2 neighbors
                if (live == 3 || (live == 2 && (board[i][j] & 1)))
                    board[i][j] |= 2;                   // set 2nd bit for next state
            }
        }

        // O(mn) second pass: shift to get next state
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};

// Solution 2: Copy Board - Time O(mn), Space O(mn)
class Solution2 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> copy = board;               // O(mn) space for board copy
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        // O(mn) iterate every cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;                           // O(1) neighbor count
                for (auto& d : dirs) {                  // O(8) = O(1) check all 8 neighbors
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                        live += copy[ni][nj];
                }
                if (copy[i][j] == 1 && (live < 2 || live > 3))
                    board[i][j] = 0;                    // under/over-population: dies
                else if (copy[i][j] == 0 && live == 3)
                    board[i][j] = 1;                    // reproduction: becomes alive
            }
        }
    }
};

#endif // LEETCODE_GAMEOFLIFE_HPP
