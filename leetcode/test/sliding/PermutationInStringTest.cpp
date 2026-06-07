#include "gtest/gtest.h"
#include "sliding/PermutationInString.hpp"

TEST(sliding, permutation_in_string) {
    Solution sol;
    // basic true
    EXPECT_TRUE(sol.checkInclusion("ab", "eidbaooo"));
    // basic false
    EXPECT_FALSE(sol.checkInclusion("ab", "eidboaoo"));
    // s1 longer than s2
    EXPECT_FALSE(sol.checkInclusion("abcdef", "ab"));
    // exact match
    EXPECT_TRUE(sol.checkInclusion("abc", "abc"));
    // single char
    EXPECT_TRUE(sol.checkInclusion("a", "a"));
    EXPECT_FALSE(sol.checkInclusion("a", "b"));
    // permutation at end
    EXPECT_TRUE(sol.checkInclusion("abc", "xyzxycba"));
    // all same chars
    EXPECT_TRUE(sol.checkInclusion("aaa", "aaaaaaa"));
    EXPECT_FALSE(sol.checkInclusion("aaa", "aa"));

    // Solution2
    Solution2 sol2;
    EXPECT_TRUE(sol2.checkInclusion("ab", "eidbaooo"));
    EXPECT_FALSE(sol2.checkInclusion("ab", "eidboaoo"));
    EXPECT_FALSE(sol2.checkInclusion("abcdef", "ab"));
    EXPECT_TRUE(sol2.checkInclusion("abc", "abc"));
    EXPECT_TRUE(sol2.checkInclusion("a", "a"));
    EXPECT_FALSE(sol2.checkInclusion("a", "b"));
    EXPECT_TRUE(sol2.checkInclusion("abc", "xyzxycba"));
    EXPECT_TRUE(sol2.checkInclusion("aaa", "aaaaaaa"));
    EXPECT_FALSE(sol2.checkInclusion("aaa", "aa"));
}
