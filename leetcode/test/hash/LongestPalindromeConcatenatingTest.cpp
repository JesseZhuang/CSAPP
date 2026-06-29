#include "gtest/gtest.h"
#include "hash/LongestPalindromeConcatenating.hpp"

TEST(hash, longest_palindrome_concatenating_example1) {
    Solution2131 sol;
    vector<string> words = {"lc", "cl", "gg"};
    EXPECT_EQ(sol.longestPalindrome(words), 6);
}

TEST(hash, longest_palindrome_concatenating_example2) {
    Solution2131 sol;
    vector<string> words = {"ab", "ty", "yt", "lc", "cl", "ab"};
    EXPECT_EQ(sol.longestPalindrome(words), 8);
}

TEST(hash, longest_palindrome_concatenating_example3) {
    Solution2131 sol;
    vector<string> words = {"cc", "ll", "xx"};
    EXPECT_EQ(sol.longestPalindrome(words), 2);
}

TEST(hash, longest_palindrome_concatenating_all_palindromic_pairs) {
    Solution2131 sol;
    vector<string> words = {"aa", "aa", "bb", "bb", "cc", "cc", "dd", "dd"};
    EXPECT_EQ(sol.longestPalindrome(words), 16);
}

TEST(hash, longest_palindrome_concatenating_palindromic_with_center) {
    Solution2131 sol;
    vector<string> words = {"aa", "aa", "aa"};
    EXPECT_EQ(sol.longestPalindrome(words), 6);
}

TEST(hash, longest_palindrome_concatenating_no_pairs) {
    Solution2131 sol;
    vector<string> words = {"ab", "cd", "ef"};
    EXPECT_EQ(sol.longestPalindrome(words), 0);
}

TEST(hash, longest_palindrome_concatenating_single_palindromic) {
    Solution2131 sol;
    vector<string> words = {"aa"};
    EXPECT_EQ(sol.longestPalindrome(words), 2);
}

TEST(hash, longest_palindrome_concatenating_empty) {
    Solution2131 sol;
    vector<string> words = {};
    EXPECT_EQ(sol.longestPalindrome(words), 0);
}

TEST(hash, longest_palindrome_concatenating_mixed) {
    Solution2131 sol;
    vector<string> words = {"ab", "ba", "cc", "cc", "dd"};
    EXPECT_EQ(sol.longestPalindrome(words), 10);
}
