#include "array/SumOfUniqueElements.hpp"
#include "gtest/gtest.h"

TEST(array, sum_of_unique_elements_singleton) {
    Solution solution;
    vector<int> nums{7};

    EXPECT_EQ(7, solution.sumOfUnique(nums));
    EXPECT_EQ(7, solution.sumOfUniqueBySorting(nums));
}

TEST(array, sum_of_unique_elements_all_distinct) {
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 5};

    EXPECT_EQ(15, solution.sumOfUnique(nums));
    EXPECT_EQ(15, solution.sumOfUniqueBySorting(nums));
}

TEST(array, sum_of_unique_elements_all_repeated) {
    Solution solution;
    vector<int> nums{2, 2, 2, 2};

    EXPECT_EQ(0, solution.sumOfUnique(nums));
    EXPECT_EQ(0, solution.sumOfUniqueBySorting(nums));
}

TEST(array, sum_of_unique_elements_mixed_frequencies) {
    Solution solution;
    vector<int> nums{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5};

    EXPECT_EQ(6, solution.sumOfUnique(nums));
    EXPECT_EQ(6, solution.sumOfUniqueBySorting(nums));
}

TEST(array, sum_of_unique_elements_sort_preserves_input) {
    Solution solution;
    vector<int> nums{4, 1, 2, 2, 3};
    const vector<int> original = nums;

    EXPECT_EQ(8, solution.sumOfUniqueBySorting(nums));
    EXPECT_EQ(original, nums);
}
