#include "util/bisect.hpp"

#include "gtest/gtest.h"

using namespace std;

class BisectTestF : public ::testing::Test {
protected:
    vector<int> nums{0, 1, 2, 4, 5};
};

TEST_F(BisectTestF, bisect_found) {
    ASSERT_EQ(2, bisect(nums, 2));
    ASSERT_EQ(3, bisect(nums, 4));
}

TEST_F(BisectTestF, bisect_not_found) {
    ASSERT_EQ(-4, bisect(nums, 3));
    ASSERT_EQ(-1, bisect(nums, -4));
}

TEST_F(BisectTestF, bisect_not_found_insert) {
    ASSERT_EQ(3, bisect(nums, 4));
    int target = 3, ind = bisect(nums, target);
    ASSERT_EQ(-4, ind);
    nums.insert(nums.begin() + ~ind, target);
    ASSERT_EQ(3, bisect(nums, target));
    ASSERT_EQ(4, bisect(nums, 4));
    ASSERT_EQ(6, nums.size());
}
