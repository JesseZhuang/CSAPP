#include "array/PartitionArrayIntoThreePartsWithEqualSum.hpp"
#include "gtest/gtest.h"

TEST(array, partition_array_into_three_parts_equal_sum_examples) {
    Solution solution;
    vector<int> first{0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    EXPECT_TRUE(solution.canThreePartsEqualSum(first));

    vector<int> second{0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    EXPECT_FALSE(solution.canThreePartsEqualSum(second));

    vector<int> third{3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    EXPECT_TRUE(solution.canThreePartsEqualSum(third));
}

TEST(array, partition_array_into_three_parts_equal_sum_all_zero) {
    Solution solution;
    vector<int> minimum{0, 0, 0};
    EXPECT_TRUE(solution.canThreePartsEqualSum(minimum));

    vector<int> extra{0, 0, 0, 0, 0};
    EXPECT_TRUE(solution.canThreePartsEqualSum(extra));
}

TEST(array, partition_array_into_three_parts_equal_sum_negative_target) {
    Solution solution;
    vector<int> arr{-1, -1, -1};
    EXPECT_TRUE(solution.canThreePartsEqualSum(arr));
}

TEST(array, partition_array_into_three_parts_equal_sum_nondivisible_total) {
    Solution solution;
    vector<int> positive{1, 1, 2};
    EXPECT_FALSE(solution.canThreePartsEqualSum(positive));

    vector<int> negative{-1, -1, -2};
    EXPECT_FALSE(solution.canThreePartsEqualSum(negative));
}

TEST(array, partition_array_into_three_parts_equal_sum_divisible_but_no_partition) {
    Solution solution;
    vector<int> arr{1, 2, 3};
    EXPECT_FALSE(solution.canThreePartsEqualSum(arr));
}

TEST(array, partition_array_into_three_parts_equal_sum_third_partition_nonempty) {
    Solution solution;
    vector<int> arr{1, -1, 1, -1};
    EXPECT_FALSE(solution.canThreePartsEqualSum(arr));

    vector<int> only_one_zero_prefix{0, 1, -1};
    EXPECT_FALSE(solution.canThreePartsEqualSum(only_one_zero_prefix));
}

TEST(array, partition_array_into_three_parts_equal_sum_zero_target_with_cancellation) {
    Solution solution;
    vector<int> arr{1, -1, 2, -2, 3, -3};
    EXPECT_TRUE(solution.canThreePartsEqualSum(arr));
}

TEST(array, partition_array_into_three_parts_equal_sum_maximum_length) {
    Solution solution;
    vector<int> arr(50'000, 0);
    arr.front() = 10'000;
    arr[25'000] = 10'000;
    arr.back() = 10'000;
    EXPECT_TRUE(solution.canThreePartsEqualSum(arr));
}
