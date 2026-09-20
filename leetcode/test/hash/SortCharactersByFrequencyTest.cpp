#include "gtest/gtest.h"
#include "hash/SortCharactersByFrequency.hpp"

#include <unordered_map>

using namespace std;

static void assert_frequency_sorted(const string &original, const string &result) {
    unordered_map<char, int> origCount, resCount;
    for (char c : original) origCount[c]++;
    for (char c : result) resCount[c]++;
    ASSERT_EQ(origCount, resCount);
    int prevFreq = INT_MAX;
    size_t i = 0;
    while (i < result.size()) {
        char c = result[i];
        int runLen = 0;
        while (i < result.size() && result[i] == c) { runLen++; i++; }
        ASSERT_EQ(origCount[c], runLen);
        ASSERT_LE(runLen, prevFreq);
        prevFreq = runLen;
    }
}

static void verify(const string &s) {
    Solution451 sol;
    assert_frequency_sorted(s, sol.frequencySortSort(s));
    assert_frequency_sorted(s, sol.frequencySortBucket(s));
}

TEST(hash, sort_characters_by_frequency_example1) { verify("tree"); }
TEST(hash, sort_characters_by_frequency_example2) { verify("cccaaa"); }
TEST(hash, sort_characters_by_frequency_example3) { verify("Aabb"); }
TEST(hash, sort_characters_by_frequency_single_char) { verify("z"); }
TEST(hash, sort_characters_by_frequency_all_same) { verify("aaaa"); }
TEST(hash, sort_characters_by_frequency_all_unique) { verify("abc"); }
TEST(hash, sort_characters_by_frequency_digits_and_letters) { verify("2a554442f544asfasssffffasss"); }
TEST(hash, sort_characters_by_frequency_case_sensitive) { verify("aAaA"); }
TEST(hash, sort_characters_by_frequency_two_chars) { verify("ab"); }
TEST(hash, sort_characters_by_frequency_long_repeated) { verify("bbbcccaaa"); }
