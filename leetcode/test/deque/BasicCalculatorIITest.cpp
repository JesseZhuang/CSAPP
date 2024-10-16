#include "gtest/gtest.h"
#include "deque/BasicCalculatorII.hpp"

using namespace std;

TEST(deque, basic_calculator_ii) {
    Solution tbt;
    ASSERT_EQ(7, tbt.calculate("3+2*2"));
    int cur = 2147483640 + '7' - '0';
    ASSERT_EQ(2147483647, cur);
    // LeetCode: runtime error: signed integer overflow: 2147483640 + 55 cannot be represented in type 'int'
}
