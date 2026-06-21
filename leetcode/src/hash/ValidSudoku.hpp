#ifndef VALID_SUDOKU_HPP
#define VALID_SUDOKU_HPP

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/// LeetCode 36, medium, tags: array, hash table, matrix.
class Solution36 {
public:
    /// HashSet approach: encode row/col/box membership as strings, check for duplicates.
    /// Time O(81) = O(1), Space O(81) = O(1) since board is fixed 9x9.
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                string row = string(1, c) + " in row " + to_string(i);
                string col = string(1, c) + " in col " + to_string(j);
                string box = string(1, c) + " in box " + to_string(i / 3) + to_string(j / 3);
                if (!seen.insert(row).second ||
                    !seen.insert(col).second ||
                    !seen.insert(box).second)
                    return false;
            }
        }
        return true;
    }
};

#endif
