#include "gtest/gtest.h"
#include "graph/SmallestStringWithSwaps.hpp"

using namespace std;

template <typename Sol>
static void run_smallest_string_cases() {
    {
        string s = "dcab";
        vector<vector<int>> pairs{{0, 3}, {1, 2}};
        EXPECT_EQ("bacd", Sol().smallestStringWithSwaps(s, pairs));
    }
    {
        string s = "dcab";
        vector<vector<int>> pairs{{0, 3}, {1, 2}, {0, 2}};
        EXPECT_EQ("abcd", Sol().smallestStringWithSwaps(s, pairs));
    }
    {
        string s = "cba";
        vector<vector<int>> pairs{{0, 1}, {1, 2}};
        EXPECT_EQ("abc", Sol().smallestStringWithSwaps(s, pairs));
    }
    {
        string s = "a";
        vector<vector<int>> pairs{};
        EXPECT_EQ("a", Sol().smallestStringWithSwaps(s, pairs));
    }
    {
        string s = "dcba";
        vector<vector<int>> pairs{};
        EXPECT_EQ("dcba", Sol().smallestStringWithSwaps(s, pairs));
    }
    {
        string s = "edcba";
        vector<vector<int>> pairs{{0, 1}, {1, 2}, {2, 3}, {3, 4}};
        EXPECT_EQ("abcde", Sol().smallestStringWithSwaps(s, pairs));
    }
    {
        string s = "dcbaf";
        vector<vector<int>> pairs{{0, 1}, {2, 3}};
        EXPECT_EQ("cdabf", Sol().smallestStringWithSwaps(s, pairs));
    }
}

TEST(graph, smallest_string_with_swaps) {
    run_smallest_string_cases<lc1202::Solution>();
}

TEST(graph, smallest_string_with_swaps2) {
    run_smallest_string_cases<lc1202::Solution2>();
}
