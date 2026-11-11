#include "gtest/gtest.h"
#include "array/SumOfBeautyInArray.hpp"

#include <numeric>
#include <utility>
#include <vector>

TEST(array, sum_of_beauties) {
    SumOfBeautyInArray::Solution solution;
    std::vector<std::pair<std::vector<int>, int>> cases = {
            {{1, 2, 3}, 2},        // Length-three global beauty takes precedence.
            {{2, 4, 6, 4}, 1},     // Local beauty only.
            {{3, 2, 1}, 0},
            {{4, 2, 3, 5}, 1},     // Every earlier value must be smaller.
            {{1, 3, 4, 2, 5}, 1},  // Every later value must be larger.
            {{1, 2, 2, 3}, 0},     // Adjacent ties fail strict comparisons.
            {{3, 1, 3, 4}, 1},     // A distant left tie blocks global beauty.
            {{1, 3, 4, 3}, 1},     // A distant right tie blocks global beauty.
            {{1, 3, 4, 5}, 4},     // Count global beauty once, as two points.
            {{1, 1, 2}, 0},
            {{1, 2, 2}, 0},
            {{100000, 100000, 100000}, 0},
            {{1, 99999, 100000}, 2},
    };

    for (auto& [nums, expected] : cases) {
        SCOPED_TRACE(::testing::PrintToString(nums));
        EXPECT_EQ(expected, solution.sumOfBeauties(nums));
    }

    std::vector<int> increasing(100000);
    std::iota(increasing.begin(), increasing.end(), 1);
    EXPECT_EQ(199996, solution.sumOfBeauties(increasing));
}
