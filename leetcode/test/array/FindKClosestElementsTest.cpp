#include "gtest/gtest.h"
#include "array/FindKClosestElements.hpp"

TEST(array, find_k_closest_elements) {
    FindKClosestElements sol;
    vector<int> a1{1, 2, 3, 4, 5};
    ASSERT_EQ(vector<int>({1, 2, 3, 4}), sol.findClosestElements(a1, 4, 3));
    vector<int> a2{1, 1, 2, 3, 4, 5};
    ASSERT_EQ(vector<int>({1, 1, 2, 3}), sol.findClosestElements(a2, 4, -1));
}
