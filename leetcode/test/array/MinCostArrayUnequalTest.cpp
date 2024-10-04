#include "gtest/gtest.h"
#include "array/MinCostArrayUnequal.hpp"


TEST(array, min_cost_unequal_array) {
    MinCostArrayUnequal tbt;
    vector<vector<int> > nums1s = {
                {1, 2, 2},
                {1, 2, 3, 4, 5},
                {2, 2, 2, 1, 3}
            },
            nums2s = {
                {1, 2, 2},
                {1, 2, 3, 4, 5},
                {1, 2, 2, 3, 3}
            };
    vector<int> expected = {-1, 10, 10};
    for (int i = 0; i < nums1s.size(); ++i)
        ASSERT_EQ(expected[i], tbt.minimumTotalCost(nums1s[i], nums2s[i]));
}

