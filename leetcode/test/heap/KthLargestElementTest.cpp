#include "gtest/gtest.h"
#include "heap/KthLargestElement.hpp"

using namespace std;

TEST(heap, kth_largest_element_heap) {
    Solution215Heap sol;
    vector<int> v1 = {3,2,1,5,6,4};       ASSERT_EQ(5, sol.findKthLargest(v1, 2));
    vector<int> v2 = {3,2,3,1,2,4,5,5,6}; ASSERT_EQ(4, sol.findKthLargest(v2, 4));
    vector<int> v3 = {1};                  ASSERT_EQ(1, sol.findKthLargest(v3, 1));
    vector<int> v4 = {7,7,7,7};            ASSERT_EQ(7, sol.findKthLargest(v4, 2));
    vector<int> v5 = {1,2,3,4,5};          ASSERT_EQ(5, sol.findKthLargest(v5, 1));
    vector<int> v6 = {5,4,3,2,1};          ASSERT_EQ(1, sol.findKthLargest(v6, 5));
    vector<int> v7 = {-1,-2,-3,-4};        ASSERT_EQ(-2, sol.findKthLargest(v7, 2));
    vector<int> v8 = {-1,2,0};             ASSERT_EQ(2, sol.findKthLargest(v8, 1));
    vector<int> v9 = {3,1,2};              ASSERT_EQ(1, sol.findKthLargest(v9, 3));
}

TEST(heap, kth_largest_element_quickselect) {
    Solution215Quickselect sol;
    vector<int> v1 = {3,2,1,5,6,4};       ASSERT_EQ(5, sol.findKthLargest(v1, 2));
    vector<int> v2 = {3,2,3,1,2,4,5,5,6}; ASSERT_EQ(4, sol.findKthLargest(v2, 4));
    vector<int> v3 = {1};                  ASSERT_EQ(1, sol.findKthLargest(v3, 1));
    vector<int> v4 = {7,7,7,7};            ASSERT_EQ(7, sol.findKthLargest(v4, 2));
    vector<int> v5 = {1,2,3,4,5};          ASSERT_EQ(5, sol.findKthLargest(v5, 1));
    vector<int> v6 = {5,4,3,2,1};          ASSERT_EQ(1, sol.findKthLargest(v6, 5));
    vector<int> v7 = {-1,-2,-3,-4};        ASSERT_EQ(-2, sol.findKthLargest(v7, 2));
    vector<int> v8 = {-1,2,0};             ASSERT_EQ(2, sol.findKthLargest(v8, 1));
    vector<int> v9 = {3,1,2};              ASSERT_EQ(1, sol.findKthLargest(v9, 3));
}
