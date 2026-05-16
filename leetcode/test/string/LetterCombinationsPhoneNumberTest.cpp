#include "gtest/gtest.h"
#include "string/LetterCombinationsPhoneNumber.hpp"

#include <algorithm>

TEST(string, letter_combinations_phone_number_iterative) {
    Solution17 tbt;

    auto r1 = tbt.letterCombinations("23");
    sort(r1.begin(), r1.end());
    ASSERT_EQ(r1, vector<string>({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));

    ASSERT_EQ(tbt.letterCombinations(""), vector<string>());

    auto r2 = tbt.letterCombinations("2");
    sort(r2.begin(), r2.end());
    ASSERT_EQ(r2, vector<string>({"a", "b", "c"}));

    auto r3 = tbt.letterCombinations("7");
    sort(r3.begin(), r3.end());
    ASSERT_EQ(r3, vector<string>({"p", "q", "r", "s"}));

    auto r4 = tbt.letterCombinations("9");
    sort(r4.begin(), r4.end());
    ASSERT_EQ(r4, vector<string>({"w", "x", "y", "z"}));

    auto r5 = tbt.letterCombinations("234");
    sort(r5.begin(), r5.end());
    ASSERT_EQ((int)r5.size(), 27);

    auto r6 = tbt.letterCombinations("22");
    sort(r6.begin(), r6.end());
    ASSERT_EQ((int)r6.size(), 9);
}

TEST(string, letter_combinations_phone_number_backtrack) {
    Solution17V2 tbt;

    auto r1 = tbt.letterCombinations("23");
    sort(r1.begin(), r1.end());
    ASSERT_EQ(r1, vector<string>({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));

    ASSERT_EQ(tbt.letterCombinations(""), vector<string>());

    auto r2 = tbt.letterCombinations("2");
    sort(r2.begin(), r2.end());
    ASSERT_EQ(r2, vector<string>({"a", "b", "c"}));

    auto r3 = tbt.letterCombinations("7");
    sort(r3.begin(), r3.end());
    ASSERT_EQ(r3, vector<string>({"p", "q", "r", "s"}));

    auto r4 = tbt.letterCombinations("9");
    sort(r4.begin(), r4.end());
    ASSERT_EQ(r4, vector<string>({"w", "x", "y", "z"}));

    auto r5 = tbt.letterCombinations("234");
    sort(r5.begin(), r5.end());
    ASSERT_EQ((int)r5.size(), 27);

    auto r6 = tbt.letterCombinations("22");
    sort(r6.begin(), r6.end());
    ASSERT_EQ((int)r6.size(), 9);
}
