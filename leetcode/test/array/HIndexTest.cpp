#include "gtest/gtest.h"
#include "array/HIndex.hpp"

TEST(array, h_index_bucket_count) {
    HIndex sol;

    vector<int> citations = {3, 0, 6, 1, 5};
    EXPECT_EQ(3, sol.hIndex(citations));

    citations = {1, 3, 1};
    EXPECT_EQ(1, sol.hIndex(citations));

    citations = {0, 0, 0};
    EXPECT_EQ(0, sol.hIndex(citations));

    citations = {4, 4, 4, 4};
    EXPECT_EQ(4, sol.hIndex(citations));

    citations = {10};
    EXPECT_EQ(1, sol.hIndex(citations));

    citations = {1000, 1000, 1000, 0};
    EXPECT_EQ(3, sol.hIndex(citations));
}

TEST(array, h_index_sort) {
    HIndex sol;

    vector<int> citations = {3, 0, 6, 1, 5};
    EXPECT_EQ(3, sol.hIndexSort(citations));

    citations = {1, 3, 1};
    EXPECT_EQ(1, sol.hIndexSort(citations));

    citations = {0, 0, 0};
    EXPECT_EQ(0, sol.hIndexSort(citations));

    citations = {4, 4, 4, 4};
    EXPECT_EQ(4, sol.hIndexSort(citations));

    citations = {10};
    EXPECT_EQ(1, sol.hIndexSort(citations));

    citations = {1000, 1000, 1000, 0};
    EXPECT_EQ(3, sol.hIndexSort(citations));
}
