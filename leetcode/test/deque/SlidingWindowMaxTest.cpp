#include "gtest/gtest.h"
#include "deque/SlidingWindowMax.hpp"

using namespace std;

TEST(deque, sliding_window_max) {
    Solution tbt{};
    vector exp{10, 10, 9, 2}, input{9, 10, 9, -7, -4, -8, 2, -6}; // i size_t underflow bug
    ASSERT_EQ(exp, tbt.maxSlidingWindow(input, 5));
}
