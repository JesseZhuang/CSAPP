#include "gtest/gtest.h"
#include "string/RemoveAllAdjacentDuplicatesInString.hpp"

#include <string>

TEST(string, remove_all_adjacent_duplicates_in_string_examples) {
    Solution1047 solution;
    EXPECT_EQ("ca", solution.removeDuplicates("abbaca"));
    EXPECT_EQ("ay", solution.removeDuplicates("azxxzy"));
}

TEST(string, remove_all_adjacent_duplicates_in_string_cascading_pairs) {
    Solution1047 solution;
    EXPECT_EQ("", solution.removeDuplicates("abccba"));
    EXPECT_EQ("", solution.removeDuplicates("aabccbaa"));
}

TEST(string, remove_all_adjacent_duplicates_in_string_singleton) {
    Solution1047 solution;
    EXPECT_EQ("a", solution.removeDuplicates("a"));
}

TEST(string, remove_all_adjacent_duplicates_in_string_no_duplicates) {
    Solution1047 solution;
    EXPECT_EQ("abcd", solution.removeDuplicates("abcd"));
}

TEST(string, remove_all_adjacent_duplicates_in_string_max_length) {
    Solution1047 solution;
    EXPECT_EQ("", solution.removeDuplicates(std::string(100000, 'a')));
}
