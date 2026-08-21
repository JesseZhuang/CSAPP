#pragma once

#include <vector>
using namespace std;

class Search2DMatrixII {
public:
    // Staircase from top-right: O(m+n) time, O(1) space
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }

    // Binary search per row: O(m log n) time, O(1) space
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        for (auto& row : matrix) {
            if (row[0] > target) break;
            if (row.back() < target) continue;
            int lo = 0, hi = (int)row.size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (row[mid] == target) return true;
                else if (row[mid] < target) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};
