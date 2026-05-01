#include "gtest/gtest.h"
#include "deque/MaxFreqStack.hpp"

TEST(deque, max_freq_stack_example1) {
    FreqStack895 fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);
    ASSERT_EQ(fs.pop(), 5);
    ASSERT_EQ(fs.pop(), 7);
    ASSERT_EQ(fs.pop(), 5);
    ASSERT_EQ(fs.pop(), 4);
}

TEST(deque, max_freq_stack_single_element) {
    FreqStack895 fs;
    fs.push(42);
    ASSERT_EQ(fs.pop(), 42);
}

TEST(deque, max_freq_stack_all_same) {
    FreqStack895 fs;
    fs.push(3);
    fs.push(3);
    fs.push(3);
    ASSERT_EQ(fs.pop(), 3);
    ASSERT_EQ(fs.pop(), 3);
    ASSERT_EQ(fs.pop(), 3);
}

TEST(deque, max_freq_stack_interleaved) {
    FreqStack895 fs;
    fs.push(1);
    fs.push(1);
    ASSERT_EQ(fs.pop(), 1);  // freq 2
    fs.push(1);
    fs.push(2);
    ASSERT_EQ(fs.pop(), 1);  // freq 2, most frequent
    ASSERT_EQ(fs.pop(), 2);  // freq 1, most recent at freq 1
    ASSERT_EQ(fs.pop(), 1);  // freq 1, remaining
}
