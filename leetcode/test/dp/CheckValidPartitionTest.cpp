#include "gtest/gtest.h"
#include "dp/CheckValidPartition.hpp"

#include <vector>

using std::vector;

TEST(dp, check_valid_partition_examples) {
    check_valid_partition::Solution solution;
    vector<int> valid = {4, 4, 4, 5, 6};
    vector<int> invalid = {1, 1, 1, 2};

    EXPECT_TRUE(solution.validPartition(valid));
    EXPECT_FALSE(solution.validPartition(invalid));
}

TEST(dp, check_valid_partition_pairs) {
    check_valid_partition::Solution solution;
    vector<int> equal = {1, 1};
    vector<int> unequal = {1, 2};

    EXPECT_TRUE(solution.validPartition(equal));
    EXPECT_FALSE(solution.validPartition(unequal));
}

TEST(dp, check_valid_partition_triples) {
    check_valid_partition::Solution solution;
    vector<int> equal = {7, 7, 7};
    vector<int> increasing = {1, 2, 3};
    vector<int> firstGap = {1, 3, 4};
    vector<int> secondGap = {1, 2, 4};
    vector<int> decreasing = {3, 2, 1};

    EXPECT_TRUE(solution.validPartition(equal));
    EXPECT_TRUE(solution.validPartition(increasing));
    EXPECT_FALSE(solution.validPartition(firstGap));
    EXPECT_FALSE(solution.validPartition(secondGap));
    EXPECT_FALSE(solution.validPartition(decreasing));
}

TEST(dp, check_valid_partition_overlapping_groups) {
    check_valid_partition::Solution solution;
    vector<int> twoPairs = {1, 1, 1, 1};
    vector<int> pairThenTriple = {1, 1, 1, 2, 3};

    EXPECT_TRUE(solution.validPartition(twoPairs));
    EXPECT_TRUE(solution.validPartition(pairThenTriple));
}

TEST(dp, check_valid_partition_invalid_prefix) {
    check_valid_partition::Solution solution;
    vector<int> nums = {1, 2, 2};

    EXPECT_FALSE(solution.validPartition(nums));
}

TEST(dp, check_valid_partition_multiple_pairs) {
    check_valid_partition::Solution solution;
    vector<int> nums = {1, 1, 2, 2, 3, 3};

    EXPECT_TRUE(solution.validPartition(nums));
}

TEST(dp, check_valid_partition_maximum_values) {
    check_valid_partition::Solution solution;
    vector<int> triple = {999998, 999999, 1000000};
    vector<int> pair = {1000000, 1000000};

    EXPECT_TRUE(solution.validPartition(triple));
    EXPECT_TRUE(solution.validPartition(pair));
}

TEST(dp, check_valid_partition_maximum_length) {
    check_valid_partition::Solution solution;
    vector<int> valid(100000, 1000000);
    vector<int> invalid(100000, 1);
    invalid.back() = 2;

    EXPECT_TRUE(solution.validPartition(valid));
    EXPECT_FALSE(solution.validPartition(invalid));
}

TEST(dp, check_valid_partition_preserves_input) {
    check_valid_partition::Solution solution;
    vector<int> nums = {4, 4, 4, 5, 6};
    const vector<int> original = nums;

    EXPECT_TRUE(solution.validPartition(nums));
    EXPECT_EQ(original, nums);
}
