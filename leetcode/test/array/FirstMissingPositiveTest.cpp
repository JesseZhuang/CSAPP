#include "gtest/gtest.h"
#include "array/FirstMissingPositive.hpp"

#include <vector>
#include <climits>

using namespace std;

TEST(array, first_missing_positive) {
    struct TestCase {
        vector<int> nums;
        int expected;
    };

    vector<TestCase> cases = {
        {{1, 2, 0}, 3},
        {{3, 4, -1, 1}, 2},
        {{7, 8, 9, 11, 12}, 1},
        {{1}, 2},
        {{2}, 1},
        {{1, 2, 3, 4, 5}, 6},
        {{1, 1, 1, 1}, 2},
        {{-1, -2, -3}, 1},
        {{INT_MAX, INT_MIN, 1, 2}, 3},
    };

    for (auto& tc : cases) {
        EXPECT_EQ(Solution41::firstMissingPositive(tc.nums), tc.expected);
    }
}

TEST(array, first_missing_positive_marking) {
    struct TestCase {
        vector<int> nums;
        int expected;
    };

    vector<TestCase> cases = {
        {{1, 2, 0}, 3},
        {{3, 4, -1, 1}, 2},
        {{7, 8, 9, 11, 12}, 1},
        {{1}, 2},
        {{2}, 1},
        {{1, 2, 3, 4, 5}, 6},
        {{1, 1, 1, 1}, 2},
        {{-1, -2, -3}, 1},
        {{INT_MAX, INT_MIN, 1, 2}, 3},
    };

    for (auto& tc : cases) {
        EXPECT_EQ(Solution41::firstMissingPositiveMarking(tc.nums), tc.expected);
    }
}
