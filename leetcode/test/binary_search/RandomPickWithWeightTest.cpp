#include <gtest/gtest.h>
#include "binary_search/RandomPickWithWeight.hpp"

TEST(binary_search, random_pick_with_weight) {
    // Single element always returns 0
    {
        vector<int> w = {1};
        RandomPickWithWeight sol(w);
        for (int i = 0; i < 100; i++) {
            EXPECT_EQ(0, sol.pickIndex());
        }
    }

    // Skewed weights [1, 99] — index 1 picked > 9000 times in 10000 trials
    {
        vector<int> w = {1, 99};
        RandomPickWithWeight sol(w);
        int count1 = 0;
        for (int i = 0; i < 10000; i++) {
            if (sol.pickIndex() == 1) count1++;
        }
        EXPECT_GT(count1, 9000);
    }

    // Valid index range
    {
        vector<int> w = {3, 5, 2, 7, 1};
        RandomPickWithWeight sol(w);
        for (int i = 0; i < 1000; i++) {
            int idx = sol.pickIndex();
            EXPECT_GE(idx, 0);
            EXPECT_LT(idx, (int)w.size());
        }
    }

    // LinearScan variant — single element
    {
        vector<int> w = {1};
        RandomPickWithWeight2 sol(w);
        for (int i = 0; i < 100; i++) {
            EXPECT_EQ(0, sol.pickIndex());
        }
    }

    // LinearScan variant — skewed weights
    {
        vector<int> w = {1, 99};
        RandomPickWithWeight2 sol(w);
        int count1 = 0;
        for (int i = 0; i < 10000; i++) {
            if (sol.pickIndex() == 1) count1++;
        }
        EXPECT_GT(count1, 9000);
    }
}
