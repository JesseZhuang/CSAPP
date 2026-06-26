#include <gtest/gtest.h>
#include "graph/OpenTheLock.hpp"

TEST(graph, open_the_lock) {
    Solution sol;
    {
        vector<string> deadends = {"0201","0101","0102","1212","2002"};
        EXPECT_EQ(sol.openLock(deadends, "0202"), 6);
    }
    {
        vector<string> deadends = {"8888"};
        EXPECT_EQ(sol.openLock(deadends, "0009"), 1);
    }
    {
        vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
        EXPECT_EQ(sol.openLock(deadends, "8888"), -1);
    }
    {
        // Start is a deadend
        vector<string> deadends = {"0000"};
        EXPECT_EQ(sol.openLock(deadends, "8888"), -1);
    }
    {
        // Target is start
        vector<string> deadends = {"1234"};
        EXPECT_EQ(sol.openLock(deadends, "0000"), 0);
    }
    {
        // Single turn
        vector<string> deadends = {};
        EXPECT_EQ(sol.openLock(deadends, "0001"), 1);
    }
    {
        // Wraparound: 9999 requires 4 turns (each digit 0->9)
        vector<string> deadends = {};
        EXPECT_EQ(sol.openLock(deadends, "9999"), 4);
    }
}

TEST(graph, open_the_lock_bidirectional) {
    SolutionBidirectional sol;
    {
        vector<string> deadends = {"0201","0101","0102","1212","2002"};
        EXPECT_EQ(sol.openLock(deadends, "0202"), 6);
    }
    {
        vector<string> deadends = {"8888"};
        EXPECT_EQ(sol.openLock(deadends, "0009"), 1);
    }
    {
        vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
        EXPECT_EQ(sol.openLock(deadends, "8888"), -1);
    }
    {
        // Start is a deadend
        vector<string> deadends = {"0000"};
        EXPECT_EQ(sol.openLock(deadends, "8888"), -1);
    }
    {
        // Target is start
        vector<string> deadends = {"1234"};
        EXPECT_EQ(sol.openLock(deadends, "0000"), 0);
    }
    {
        // Single turn
        vector<string> deadends = {};
        EXPECT_EQ(sol.openLock(deadends, "0001"), 1);
    }
    {
        // Wraparound: 9999 requires 4 turns (each digit 0->9)
        vector<string> deadends = {};
        EXPECT_EQ(sol.openLock(deadends, "9999"), 4);
    }
}
