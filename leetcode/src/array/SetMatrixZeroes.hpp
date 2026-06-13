#ifndef SETMATRIXZEROES_HPP
#define SETMATRIXZEROES_HPP

#include <vector>
#include <unordered_set>

using namespace std;

// LeetCode 73, medium, tags: array, hash table, matrix.
class SetMatrixZeroes {
public:
    // O(mn) time, O(1) space. Use first row/col as markers.
    static void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool col0 = false;
        for (int i = 0; i < m; i++) { // O(m)
            if (matrix[i][0] == 0) col0 = true;
            for (int j = 1; j < n; j++) // O(n)
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
        }
        for (int i = m - 1; i >= 0; i--) { // O(m)
            for (int j = n - 1; j >= 1; j--) // O(n)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            if (col0) matrix[i][0] = 0;
        }
    }

    // O(mn) time, O(m+n) space. Use sets.
    static void setZeroesV2(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) { rows.insert(i); cols.insert(j); }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rows.count(i) || cols.count(j)) matrix[i][j] = 0;
    }
};

#endif
