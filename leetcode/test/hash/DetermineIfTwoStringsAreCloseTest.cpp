#include "gtest/gtest.h"
#include "hash/DetermineIfTwoStringsAreClose.hpp"

#include <string>

TEST(hash, determine_if_two_strings_are_close_anagrams) {
    Solution sol;

    EXPECT_TRUE(sol.closeStrings("abc", "bca"));
}

TEST(hash, determine_if_two_strings_are_close_different_lengths) {
    Solution sol;

    EXPECT_FALSE(sol.closeStrings("a", "aa"));
}

TEST(hash, determine_if_two_strings_are_close_swapped_frequencies) {
    Solution sol;

    EXPECT_TRUE(sol.closeStrings("cabbba", "abbccc"));
    EXPECT_TRUE(sol.closeStrings("aaabbc", "aabbbc"));
}

TEST(hash, determine_if_two_strings_are_close_different_characters) {
    Solution sol;

    EXPECT_FALSE(sol.closeStrings("ab", "cd"));
    EXPECT_FALSE(sol.closeStrings("a", "z"));
}

TEST(hash, determine_if_two_strings_are_close_different_frequency_multisets) {
    Solution sol;

    EXPECT_FALSE(sol.closeStrings("aaabbc", "aabbcc"));
    EXPECT_FALSE(sol.closeStrings("aabb", "abbb"));
}

TEST(hash, determine_if_two_strings_are_close_boundaries) {
    Solution sol;

    EXPECT_TRUE(sol.closeStrings("", ""));
    EXPECT_TRUE(sol.closeStrings("z", "z"));
    EXPECT_TRUE(sol.closeStrings("zzzz", "zzzz"));
    EXPECT_FALSE(sol.closeStrings("", "a"));
}

TEST(hash, determine_if_two_strings_are_close_max_length) {
    Solution sol;
    const std::string word1 = std::string(50000, 'a') + std::string(30000, 'b') + std::string(20000, 'z');
    const std::string word2 = std::string(50000, 'z') + std::string(30000, 'a') + std::string(20000, 'b');

    EXPECT_TRUE(sol.closeStrings(word1, word2));
    EXPECT_FALSE(sol.closeStrings(std::string(100000, 'a'), std::string(99999, 'a') + "z"));
}
