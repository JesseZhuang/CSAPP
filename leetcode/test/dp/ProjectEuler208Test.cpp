#include "gtest/gtest.h"
#include "dp/ProjectEuler208.hpp"

using namespace std;

TEST(dp, euler_208_test) {
    Solution tbt(20);
    ASSERT_EQ(3400, tbt.journeys());
    tbt = Solution(25);
    ASSERT_EQ(70932, tbt.journeys());
    tbt = Solution(70);
    ASSERT_EQ(331951449665644800, tbt.journeys());
    tbt = Solution(6);
    ASSERT_EQ(0, tbt.journeys());
}
