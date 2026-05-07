#include "gtest/gtest.h"
#include "array/ContainerWithMostWater.hpp"

TEST(array, container_with_most_water) {
    ContainerWithMostWater sol;

    vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    EXPECT_EQ(49, sol.maxArea(h1));

    vector<int> h2 = {1,1};
    EXPECT_EQ(1, sol.maxArea(h2));

    vector<int> h3 = {4,3,2,1,4};
    EXPECT_EQ(16, sol.maxArea(h3));

    vector<int> h4 = {5,5,5,5,5};
    EXPECT_EQ(20, sol.maxArea(h4));

    vector<int> h5 = {3,100};
    EXPECT_EQ(3, sol.maxArea(h5));

    vector<int> h6 = {10,1,1,1,1,1,1,1,10};
    EXPECT_EQ(80, sol.maxArea(h6));
}
