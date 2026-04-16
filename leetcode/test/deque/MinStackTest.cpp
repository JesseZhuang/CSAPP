#include "gtest/gtest.h"
#include "deque/MinStack.hpp"

TEST(deque, min_stack_two_stacks) {
    MinStack155 ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    ASSERT_EQ(-3, ms.getMin());
    ms.pop();
    ASSERT_EQ(0, ms.top());
    ASSERT_EQ(-2, ms.getMin());
}

TEST(deque, min_stack_two_stacks_decreasing) {
    MinStack155 ms;
    ms.push(3);
    ms.push(2);
    ms.push(1);
    ASSERT_EQ(1, ms.getMin());
    ms.pop();
    ASSERT_EQ(2, ms.getMin());
    ms.pop();
    ASSERT_EQ(3, ms.getMin());
}

TEST(deque, min_stack_two_stacks_large_small) {
    MinStack155 ms;
    ms.push(1000);
    ms.push(-1000);
    ASSERT_EQ(-1000, ms.getMin());
    ms.pop();
    ASSERT_EQ(1000, ms.getMin());
}

TEST(deque, min_stack_single_stack) {
    MinStack155V2 ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    ASSERT_EQ(-3, ms.getMin());
    ms.pop();
    ASSERT_EQ(0, ms.top());
    ASSERT_EQ(-2, ms.getMin());
}

TEST(deque, min_stack_single_stack_decreasing) {
    MinStack155V2 ms;
    ms.push(3);
    ms.push(2);
    ms.push(1);
    ASSERT_EQ(1, ms.getMin());
    ms.pop();
    ASSERT_EQ(2, ms.getMin());
    ms.pop();
    ASSERT_EQ(3, ms.getMin());
}
