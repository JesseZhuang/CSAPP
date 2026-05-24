#pragma once
#include <vector>
using namespace std;

// LeetCode 74 - Search a 2D Matrix
// Each row sorted left-to-right; first element of each row > last element of previous row.

class Solution {
public:
    // Approach 1: Treat matrix as a flattened sorted array, single binary search.
    // Time: O(log(m*n)), Space: O(1)
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m * n - 1;
        // O(log(m*n)) iterations — standard binary search over virtual 1D array
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = matrix[mid / n][mid % n];
            if (val == target) return true;
            else if (val < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }

    // Approach 2: Binary search for the correct row, then binary search within that row.
    // Time: O(log m + log n), Space: O(1)
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        // O(log m) iterations — find the row where target could reside
        int lo = 0, hi = m - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
                // Target must be in this row; binary search within it
                int left = 0, right = n - 1;
                // O(log n) iterations — standard binary search within the row
                while (left <= right) {
                    int col = left + (right - left) / 2;
                    if (matrix[mid][col] == target) return true;
                    else if (matrix[mid][col] < target) left = col + 1;
                    else right = col - 1;
                }
                return false;
            } else if (matrix[mid][0] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};
