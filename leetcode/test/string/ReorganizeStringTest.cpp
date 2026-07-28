#include "gtest/gtest.h"
#include "string/ReorganizeString.hpp"

#include <algorithm>

static bool isValid(const string &result, const string &s) {
    if (result.empty()) return false;
    string r = result, o = s;
    sort(r.begin(), r.end());
    sort(o.begin(), o.end());
    if (r != o) return false;
    for (int i = 1; i < (int) result.size(); i++)
        if (result[i] == result[i - 1]) return false;
    return true;
}

TEST(string, reorganize_string_possible) {
    Solution sol;
    EXPECT_TRUE(isValid(sol.reorganizeString("aab"), "aab"));
    EXPECT_TRUE(isValid(sol.reorganizeString("a"), "a"));
    EXPECT_TRUE(isValid(sol.reorganizeString("ab"), "ab"));
    EXPECT_TRUE(isValid(sol.reorganizeString("aabb"), "aabb"));
    EXPECT_TRUE(isValid(sol.reorganizeString("aaabb"), "aaabb"));
    EXPECT_TRUE(isValid(sol.reorganizeString("vvvlo"), "vvvlo"));
}

TEST(string, reorganize_string_impossible) {
    Solution sol;
    EXPECT_EQ(sol.reorganizeString("aaab"), "");
    EXPECT_EQ(sol.reorganizeString("aa"), "");
    EXPECT_EQ(sol.reorganizeString("aaaa"), "");
}
