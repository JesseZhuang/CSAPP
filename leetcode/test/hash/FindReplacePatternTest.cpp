#include "gtest/gtest.h"
#include "hash/FindReplacePattern.hpp"

using namespace std;

TEST(hash, find_replace_pattern) {
    Solution tbt;
    vector<string> words{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    vector<string> res = tbt.findAndReplacePattern(words, pattern);
    ASSERT_EQ(res.size(), 2);
    ASSERT_EQ(res, vector<string>({"mee", "aqq"}));
}
