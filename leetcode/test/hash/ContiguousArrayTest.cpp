#include "gtest/gtest.h"
#include "hash/ContiguousArray.hpp"

TEST(hash, contiguous_array) {
    ContiguousArray sol;

    vector<int> t1 = {0, 1};
    EXPECT_EQ(2, sol.findMaxLength(t1));

    vector<int> t2 = {0, 1, 0};
    EXPECT_EQ(2, sol.findMaxLength(t2));

    vector<int> t3 = {0, 0, 0};
    EXPECT_EQ(0, sol.findMaxLength(t3));

    vector<int> t4 = {0, 1, 1, 0};
    EXPECT_EQ(4, sol.findMaxLength(t4));

    vector<int> t5 = {0, 0, 1, 0, 0, 0, 1, 1};
    EXPECT_EQ(6, sol.findMaxLength(t5));
}
