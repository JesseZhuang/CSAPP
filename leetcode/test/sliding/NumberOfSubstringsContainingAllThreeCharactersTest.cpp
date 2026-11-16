#include "gtest/gtest.h"
#include "sliding/NumberOfSubstringsContainingAllThreeCharacters.hpp"
#include <string>
#include <utility>
#include <vector>

TEST(sliding, number_of_substrings_containing_all_three_characters) {
    SolutionNumberOfSubstringsContainingAllThreeCharacters sol;

    for (const auto& [s, expected] : vector<pair<string, int>>{
            {"abcabc", 10}, {"aaacb", 3}, {"abc", 1},
            {"aaaa", 0}, {"ababab", 0}, {"bc", 0},
            {"aabbcc", 4}, {"abccba", 7}, {"", 0}}) {
        SCOPED_TRACE(s);
        EXPECT_EQ(expected, sol.numberOfSubstrings(s));
        EXPECT_EQ(expected, sol.numberOfSubstringsSlidingWindow(s));
    }
}

TEST(sliding, number_of_substrings_containing_all_three_characters_boundary) {
    SolutionNumberOfSubstringsContainingAllThreeCharacters sol;
    string s;
    s.reserve(50000);
    for (int i = 0; i < 16666; ++i) {
        s += "abc";
    }
    s += "ab";

    EXPECT_EQ(1249925001, sol.numberOfSubstrings(s));
    EXPECT_EQ(1249925001, sol.numberOfSubstringsSlidingWindow(s));
}
