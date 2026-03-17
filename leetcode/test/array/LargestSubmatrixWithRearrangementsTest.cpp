#include "gtest/gtest.h"
#include "array/LargestSubmatrixWithRearrangements.hpp"

using namespace std;

TEST(array, largest_submatrix_with_rearrangements) {
    Solution tbt;
    Solution1 tbt1;
    vector<vector<vector<int>>> cases = {
            {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}},
            {{1, 0, 1, 0, 1}},
            {{0, 0}, {0, 0}},
            {{1, 1, 1}, {1, 1, 1}},
            {{1, 0, 1, 1}},
            {{1}, {0}, {1}, {1}}
    };
    vector<int> expected = {4, 3, 0, 6, 3, 2};
    for (int i = 0; i < cases.size(); ++i) {
        ASSERT_EQ(expected[i], tbt.largestSubmatrix(cases[i]));
        ASSERT_EQ(expected[i], tbt1.largestSubmatrix(cases[i]));
    }
}
