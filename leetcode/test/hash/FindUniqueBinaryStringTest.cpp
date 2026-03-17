#include "gtest/gtest.h"
#include "hash/FindUniqueBinaryString.hpp"

using namespace std;

static void assert_valid(const vector<string> &nums, const string &ans) {
    ASSERT_EQ(ans.size(), nums.size());
    for (const auto &s : nums) {
        ASSERT_NE(ans, s);
    }
}

TEST(hash, find_unique_binary_string_example1) {
    Solution sol;
    vector<string> nums{"01", "10"};
    assert_valid(nums, sol.findDifferentBinaryString(nums));
    assert_valid(nums, sol.findDifferentBinaryStringSet(nums));
}

TEST(hash, find_unique_binary_string_example2) {
    Solution sol;
    vector<string> nums{"00", "01"};
    assert_valid(nums, sol.findDifferentBinaryString(nums));
    assert_valid(nums, sol.findDifferentBinaryStringSet(nums));
}

TEST(hash, find_unique_binary_string_example3) {
    Solution sol;
    vector<string> nums{"111", "011", "001"};
    assert_valid(nums, sol.findDifferentBinaryString(nums));
    assert_valid(nums, sol.findDifferentBinaryStringSet(nums));
}

TEST(hash, find_unique_binary_string_n1_zero) {
    Solution sol;
    vector<string> nums{"0"};
    assert_valid(nums, sol.findDifferentBinaryString(nums));
    assert_valid(nums, sol.findDifferentBinaryStringSet(nums));
}

TEST(hash, find_unique_binary_string_n1_one) {
    Solution sol;
    vector<string> nums{"1"};
    assert_valid(nums, sol.findDifferentBinaryString(nums));
    assert_valid(nums, sol.findDifferentBinaryStringSet(nums));
}
