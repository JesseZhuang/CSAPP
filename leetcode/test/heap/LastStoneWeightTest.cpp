#include "gtest/gtest.h"
#include "heap/LastStoneWeight.hpp"

TEST(heap, last_stone_weight) {
    Solution sol;
    Solution2 sol2;

    auto run = [&](vector<int> stones, int expected) {
        vector<int> copy = stones;
        ASSERT_EQ(expected, sol.lastStoneWeight(stones));
        ASSERT_EQ(expected, sol2.lastStoneWeight(copy));
    };

    run({2, 7, 4, 1, 8, 1}, 1);
    run({1}, 1);
    run({3, 3}, 0);
    run({3, 7}, 4);
    run({5, 5, 5, 5}, 0);
    run({5, 5, 5}, 5);
    run({10, 4, 2, 10}, 2);
    run({42}, 42);
    run({1000, 999}, 1);
    run({100, 1, 1, 1, 1}, 96);
}
