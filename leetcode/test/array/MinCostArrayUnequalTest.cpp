#include <boost/test/unit_test.hpp>
#include "array/MinCostArrayUnequal.hpp"

BOOST_AUTO_TEST_SUITE(leetcode)

    BOOST_AUTO_TEST_CASE(min_cost_unequal_array) {
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
            BOOST_CHECK_EQUAL(expected[i], tbt.minimumTotalCost(nums1s[i], nums2s[i]));
    }

BOOST_AUTO_TEST_SUITE_END()
