#include "gtest/gtest.h"
#include "array/FindDuplicateNumber.hpp"

#include <vector>

using namespace std;

TEST(array, find_duplicate_number) {
    struct TestCase {
        vector<int> nums;
        int expected;
    };

    vector<TestCase> cases = {
        {{1, 3, 4, 2, 2}, 2},
        {{3, 1, 3, 4, 2}, 3},
        {{1, 1, 1, 1, 1}, 1},
        {{1, 1}, 1},
        {{2, 2, 2, 2, 2}, 2},
        {{1, 4, 4, 2, 3}, 4},
        {{1, 2, 3, 4, 4}, 4},
        {{5, 1, 2, 3, 4, 5}, 5},
    };

    for (auto& tc : cases) {
        EXPECT_EQ(Solution287::findDuplicate(tc.nums), tc.expected);
        EXPECT_EQ(Solution287::findDuplicate2(tc.nums), tc.expected);
    }
}
