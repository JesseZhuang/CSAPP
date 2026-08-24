#ifndef LEETCODE_MAXIMALRECTANGLE_HPP
#define LEETCODE_MAXIMALRECTANGLE_HPP

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Solution 1: Histogram + Monotonic Stack
// Build histogram row by row, apply largest-rectangle-in-histogram per row.
// Time O(m*n), Space O(n).
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) { // O(m) rows
            // Update histogram heights for current row — O(n)
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            // Largest rectangle in histogram using monotonic stack — O(n)
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea; // Total: O(m*n)
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        stack<int> st; // monotonic increasing stack of indices
        int maxArea = 0;
        for (int i = 0; i <= n; i++) { // O(n) — each index pushed/popped at most once
            int h = i == n ? 0 : heights[i];
            while (!st.empty() && h < heights[st.top()]) {
                int curHeight = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, curHeight * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

// Solution 2: DP approach with height/left/right arrays.
// For each cell, track the height of consecutive '1's above,
// and the left/right boundaries of the rectangle at that height.
// Time O(m*n), Space O(n).
class Solution2 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());

        vector<int> height(n, 0);
        vector<int> left(n, 0);    // left boundary of rectangle at current height
        vector<int> right(n, n);   // right boundary (exclusive) of rectangle

        int maxArea = 0;

        for (int i = 0; i < m; i++) { // O(m) rows
            int curLeft = 0, curRight = n;

            // Update heights — O(n)
            for (int j = 0; j < n; j++) {
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            }

            // Update left boundaries — O(n)
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                } else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }

            // Update right boundaries — O(n)
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = n;
                    curRight = j;
                }
            }

            // Compute max area — O(n)
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, height[j] * (right[j] - left[j]));
            }
        }
        return maxArea; // Total: O(m*n)
    }
};

#endif //LEETCODE_MAXIMALRECTANGLE_HPP
