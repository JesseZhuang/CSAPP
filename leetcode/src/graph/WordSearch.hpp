#ifndef WORD_SEARCH_HPP
#define WORD_SEARCH_HPP

#include <string>
#include <vector>

using namespace std;

// O(mn * 4^l) time, O(mn) space for visited (or O(l) recursion stack).
class WordSearch {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, 0, i, j)) return true;
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, const string &word, int idx, int i, int j) {
        if (idx == (int) word.size()) return true;
        if (i < 0 || i >= (int) board.size() || j < 0 || j >= (int) board[0].size()) return false;
        if (board[i][j] != word[idx]) return false;
        char tmp = board[i][j];
        board[i][j] = '#';
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto &d : dirs)
            if (dfs(board, word, idx + 1, i + d[0], j + d[1])) return true;
        board[i][j] = tmp;
        return false;
    }
};

#endif
