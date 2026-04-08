#ifndef LEETCODE_KTHSMALLESTMATRIX_HPP
#define LEETCODE_KTHSMALLESTMATRIX_HPP

#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix.front().front();
        int right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countLessEqual(matrix, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int kthSmallestHeap(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> min_heap;
        int rows = static_cast<int>(matrix.size());
        for (int row = 0; row < min(rows, k); ++row) {
            min_heap.emplace(matrix[row][0], row, 0);
        }

        int value = matrix[0][0];
        for (int i = 0; i < k; ++i) {
            auto [cur, row, col] = min_heap.top();
            min_heap.pop();
            value = cur;
            if (col + 1 < static_cast<int>(matrix[row].size())) {
                min_heap.emplace(matrix[row][col + 1], row, col + 1);
            }
        }
        return value;
    }

private:
    int countLessEqual(const vector<vector<int>>& matrix, int target) {
        int row = static_cast<int>(matrix.size()) - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < static_cast<int>(matrix[0].size())) {
            if (matrix[row][col] <= target) {
                count += row + 1;
                ++col;
            } else {
                --row;
            }
        }
        return count;
    }
};

#endif // LEETCODE_KTHSMALLESTMATRIX_HPP
