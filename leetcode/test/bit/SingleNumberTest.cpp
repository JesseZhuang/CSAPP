#include <vector>
#include <gtest/gtest.h>
#include "bit/SingleNumber.hpp"

namespace {
struct SingleNumberCase {
    std::vector<int> nums;
    int expected;
};

const SingleNumberCase cases[] = {
    {{2, 2, 1}, 1},
    {{4, 1, 2, 1, 2}, 4},
    {{1}, 1},
    {{-2, 0, -3, -2, 0}, -3},
    {{-1, 2, 0, -1, 2}, 0},
};
}

TEST(bit, single_number) {
    Solution136 sol;
    for (const auto& testCase : cases) {
        SCOPED_TRACE(testing::PrintToString(testCase.nums));
        EXPECT_EQ(testCase.expected, sol.singleNumber(testCase.nums));
    }
}

TEST(bit, single_number_hash_set) {
    Solution136 sol;
    for (const auto& testCase : cases) {
        SCOPED_TRACE(testing::PrintToString(testCase.nums));
        EXPECT_EQ(testCase.expected, sol.singleNumberHashSet(testCase.nums));
    }
}
