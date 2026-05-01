#include "gtest/gtest.h"
#include "hash/WordSubsets.hpp"

using namespace std;

TEST(hash, word_subsets_example1) {
    Solution916 sol;
    vector<string> words1{"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2{"e", "o"};
    vector<string> expected{"facebook", "google", "leetcode"};
    ASSERT_EQ(expected, sol.wordSubsets(words1, words2));
}

TEST(hash, word_subsets_example2) {
    Solution916 sol;
    vector<string> words1{"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2{"l", "e"};
    vector<string> expected{"apple", "google", "leetcode"};
    ASSERT_EQ(expected, sol.wordSubsets(words1, words2));
}
