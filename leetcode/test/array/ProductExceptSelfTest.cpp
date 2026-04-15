#include "gtest/gtest.h"
#include "array/ProductExceptSelf.hpp"
#include <vector>

using namespace std;

TEST(array, product_except_self) {
    Solution sol;
    Solution2 sol2;
    vector<pair<vector<int>, vector<int>>> cases = {
        {{1,2,3,4}, {24,12,8,6}},
        {{-1,1,0,-3,3}, {0,0,9,0,0}},
        {{0,0}, {0,0}},
        {{1,0}, {0,1}},
        {{2,3}, {3,2}},
        {{5}, {1}},
        {{1,2,3,4,5}, {120,60,40,30,24}},
    };
    for (auto &[nums, exp] : cases) {
        ASSERT_EQ(exp, sol.productExceptSelf(nums));
        ASSERT_EQ(exp, sol2.productExceptSelf(nums));
    }
}
