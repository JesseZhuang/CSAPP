#include "gtest/gtest.h"
#include "string/ReversePrefixOfWord.hpp"

#include <string>

TEST(string, reverse_prefix_of_word_examples) {
    Solution2000 solution;
    EXPECT_EQ("dcbaefd", solution.reversePrefix("abcdefd", 'd'));
    EXPECT_EQ("zxyxxe", solution.reversePrefix("xyxzxe", 'z'));
    EXPECT_EQ("abcd", solution.reversePrefix("abcd", 'z'));
}

TEST(string, reverse_prefix_of_word_first_occurrence_only) {
    Solution2000 solution;
    EXPECT_EQ("cbacc", solution.reversePrefix("abccc", 'c'));
    EXPECT_EQ("cbbac", solution.reversePrefix("abbcc", 'c'));
}

TEST(string, reverse_prefix_of_word_boundaries) {
    Solution2000 solution;
    EXPECT_EQ("a", solution.reversePrefix("a", 'a'));
    EXPECT_EQ("a", solution.reversePrefix("a", 'z'));
    EXPECT_EQ("abcde", solution.reversePrefix("abcde", 'a'));
    EXPECT_EQ("edcba", solution.reversePrefix("abcde", 'e'));
    EXPECT_EQ("bacde", solution.reversePrefix("abcde", 'b'));
    EXPECT_EQ("cbade", solution.reversePrefix("abcde", 'c'));
}

TEST(string, reverse_prefix_of_word_maximum_length) {
    Solution2000 solution;
    std::string word(249, 'a');
    word += 'z';
    std::string reversed = "z" + std::string(249, 'a');
    EXPECT_EQ(reversed, solution.reversePrefix(word, 'z'));
    EXPECT_EQ(word, solution.reversePrefix(word, 'b'));
}
