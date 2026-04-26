#include "gtest/gtest.h"
#include "hash/LongestConsecutiveSequence.hpp"

#include <vector>

using namespace std;

TEST(hash, longest_consecutive_set_example1) {
    Solution128 sol;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    ASSERT_EQ(4, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_set_example2) {
    Solution128 sol;
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    ASSERT_EQ(9, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_set_empty) {
    Solution128 sol;
    vector<int> nums{};
    ASSERT_EQ(0, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_set_single) {
    Solution128 sol;
    vector<int> nums{1};
    ASSERT_EQ(1, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_set_duplicates) {
    Solution128 sol;
    vector<int> nums{1, 2, 0, 1};
    ASSERT_EQ(3, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_set_negative) {
    Solution128 sol;
    vector<int> nums{-3, -2, -1, 0, 1, 2};
    ASSERT_EQ(6, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_set_no_consecutive) {
    Solution128 sol;
    vector<int> nums{10, 20, 30, 40};
    ASSERT_EQ(1, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_set_all_same) {
    Solution128 sol;
    vector<int> nums{5, 5, 5, 5};
    ASSERT_EQ(1, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_set_two_sequences) {
    Solution128 sol;
    vector<int> nums{1, 2, 3, 10, 11, 12, 13};
    ASSERT_EQ(4, sol.longestConsecutiveSet(nums));
}

TEST(hash, longest_consecutive_uf_example1) {
    Solution128 sol;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    ASSERT_EQ(4, sol.longestConsecutiveUF(nums));
}

TEST(hash, longest_consecutive_uf_example2) {
    Solution128 sol;
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    ASSERT_EQ(9, sol.longestConsecutiveUF(nums));
}

TEST(hash, longest_consecutive_uf_empty) {
    Solution128 sol;
    vector<int> nums{};
    ASSERT_EQ(0, sol.longestConsecutiveUF(nums));
}

TEST(hash, longest_consecutive_uf_single) {
    Solution128 sol;
    vector<int> nums{1};
    ASSERT_EQ(1, sol.longestConsecutiveUF(nums));
}

TEST(hash, longest_consecutive_uf_duplicates) {
    Solution128 sol;
    vector<int> nums{1, 2, 0, 1};
    ASSERT_EQ(3, sol.longestConsecutiveUF(nums));
}

TEST(hash, longest_consecutive_uf_negative) {
    Solution128 sol;
    vector<int> nums{-3, -2, -1, 0, 1, 2};
    ASSERT_EQ(6, sol.longestConsecutiveUF(nums));
}

TEST(hash, longest_consecutive_uf_no_consecutive) {
    Solution128 sol;
    vector<int> nums{10, 20, 30, 40};
    ASSERT_EQ(1, sol.longestConsecutiveUF(nums));
}

TEST(hash, longest_consecutive_uf_all_same) {
    Solution128 sol;
    vector<int> nums{5, 5, 5, 5};
    ASSERT_EQ(1, sol.longestConsecutiveUF(nums));
}

TEST(hash, longest_consecutive_uf_two_sequences) {
    Solution128 sol;
    vector<int> nums{1, 2, 3, 10, 11, 12, 13};
    ASSERT_EQ(4, sol.longestConsecutiveUF(nums));
}
