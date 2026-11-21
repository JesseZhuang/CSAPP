#include "gtest/gtest.h"
#include "string/MinimumDeletionsToMakeStringBalanced.hpp"

#include <utility>

TEST(string, minimum_deletions_to_make_string_balanced) {
    Solution1653 solution;
    const vector<pair<string, int>> cases = {
        {"a", 0},
        {"b", 0},
        {"aaaa", 0},
        {"bbbb", 0},
        {"aaabbb", 0},
        {"aabbab", 1},
        {"bbaaaa", 2},
        {"aababbab", 2},
    };

    for (const auto &[s, expected] : cases) {
        EXPECT_EQ(expected, solution.minimumDeletions(s)) << "s=" << s;
        EXPECT_EQ(expected, solution.minimumDeletionsBySplit(s)) << "s=" << s;
    }

    const string maximumLength = string(50000, 'b') + string(50000, 'a');
    EXPECT_EQ(50000, solution.minimumDeletions(maximumLength));
    EXPECT_EQ(50000, solution.minimumDeletionsBySplit(maximumLength));
}
