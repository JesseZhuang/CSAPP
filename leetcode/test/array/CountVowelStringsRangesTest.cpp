#include "array/CountVowelStringsRanges.hpp"
#include <gtest/gtest.h>

TEST(array, count_vowel_strings_ranges) {
    SolutionCountVowelStringsRanges sol;
    vector<string> words1 = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries1 = {{0, 2}, {1, 4}, {1, 1}};
    vector<int> expected1 = {2, 3, 0};
    EXPECT_EQ(sol.vowelStrings(words1, queries1), expected1);

    vector<string> words2 = {"a", "e", "i"};
    vector<vector<int>> queries2 = {{0, 2}, {0, 1}, {2, 2}};
    vector<int> expected2 = {3, 2, 1};
    EXPECT_EQ(sol.vowelStrings(words2, queries2), expected2);

    // single word, not vowel
    vector<string> words3 = {"bcd"};
    vector<vector<int>> queries3 = {{0, 0}};
    vector<int> expected3 = {0};
    EXPECT_EQ(sol.vowelStrings(words3, queries3), expected3);

    // single vowel word
    vector<string> words4 = {"ae"};
    vector<vector<int>> queries4 = {{0, 0}};
    vector<int> expected4 = {1};
    EXPECT_EQ(sol.vowelStrings(words4, queries4), expected4);
}
