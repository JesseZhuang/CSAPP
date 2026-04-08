#include "gtest/gtest.h"
#include "array/KthSmallestMatrix.hpp"

using namespace std;

TEST(array, kth_smallest_matrix_binary_search) {
    Solution sol;
    vector<vector<int>> matrix1{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    vector<vector<int>> matrix2{{-5}};
    vector<vector<int>> matrix3{{1, 2}, {1, 3}};
    vector<vector<int>> matrix4{{-10, -5, 0}, {-8, -3, 2}, {-6, 1, 4}};
    ASSERT_EQ(13, sol.kthSmallest(matrix1, 8));
    ASSERT_EQ(-5, sol.kthSmallest(matrix2, 1));
    ASSERT_EQ(1, sol.kthSmallest(matrix3, 2));
    ASSERT_EQ(-3, sol.kthSmallest(matrix4, 5));
}

TEST(array, kth_smallest_matrix_heap) {
    Solution sol;
    vector<vector<int>> matrix1{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    vector<vector<int>> matrix2{{-5}};
    vector<vector<int>> matrix3{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    ASSERT_EQ(13, sol.kthSmallestHeap(matrix1, 8));
    ASSERT_EQ(-5, sol.kthSmallestHeap(matrix2, 1));
    ASSERT_EQ(5, sol.kthSmallestHeap(matrix3, 9));
    ASSERT_EQ(1, sol.kthSmallestHeap(matrix3, 1));
}
