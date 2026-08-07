#include "gtest/gtest.h"
#include "dp/PalindromePartitioning.hpp"
#include <algorithm>

TEST(dp, palindrome_partitioning) {
    Solution sol;

    auto res1 = sol.partition("aab");
    vector<vector<string>> expected1 = {{"a", "a", "b"}, {"aa", "b"}};
    sort(res1.begin(), res1.end());
    sort(expected1.begin(), expected1.end());
    ASSERT_EQ(expected1, res1);

    auto res2 = sol.partition("a");
    vector<vector<string>> expected2 = {{"a"}};
    ASSERT_EQ(expected2, res2);

    auto res3 = sol.partition("aba");
    vector<vector<string>> expected3 = {{"a", "b", "a"}, {"aba"}};
    sort(res3.begin(), res3.end());
    sort(expected3.begin(), expected3.end());
    ASSERT_EQ(expected3, res3);

    auto res4 = sol.partition("aaa");
    vector<vector<string>> expected4 = {{"a", "a", "a"}, {"a", "aa"}, {"aa", "a"}, {"aaa"}};
    sort(res4.begin(), res4.end());
    sort(expected4.begin(), expected4.end());
    ASSERT_EQ(expected4, res4);
}

TEST(dp, palindrome_partitioning2) {
    Solution2 sol;

    auto res1 = sol.partition("aab");
    vector<vector<string>> expected1 = {{"a", "a", "b"}, {"aa", "b"}};
    sort(res1.begin(), res1.end());
    sort(expected1.begin(), expected1.end());
    ASSERT_EQ(expected1, res1);

    auto res2 = sol.partition("a");
    vector<vector<string>> expected2 = {{"a"}};
    ASSERT_EQ(expected2, res2);

    auto res3 = sol.partition("aba");
    vector<vector<string>> expected3 = {{"a", "b", "a"}, {"aba"}};
    sort(res3.begin(), res3.end());
    sort(expected3.begin(), expected3.end());
    ASSERT_EQ(expected3, res3);

    auto res4 = sol.partition("aaa");
    vector<vector<string>> expected4 = {{"a", "a", "a"}, {"a", "aa"}, {"aa", "a"}, {"aaa"}};
    sort(res4.begin(), res4.end());
    sort(expected4.begin(), expected4.end());
    ASSERT_EQ(expected4, res4);
}
