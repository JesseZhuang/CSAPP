#include "gtest/gtest.h"
#include "hash/GroupAnagrams.hpp"

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

namespace {
    vector<vector<string>> normalize(vector<vector<string>> groups) {
        for (auto &g : groups) sort(g.begin(), g.end());
        sort(groups.begin(), groups.end(),
             [](const auto &a, const auto &b) { return a[0] < b[0]; });
        return groups;
    }
}

TEST(hash, group_anagrams_sort) {
    Solution49 sol;
    vector<string> v1{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto expected = vector<vector<string>>{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsSort(v1)));
}

TEST(hash, group_anagrams_count) {
    Solution49 sol;
    vector<string> v1{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto expected = vector<vector<string>>{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsCount(v1)));
}

TEST(hash, group_anagrams_empty_string) {
    Solution49 sol;
    vector<string> v{""};
    auto expected = vector<vector<string>>{{""}};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsSort(v)));
    vector<string> v2{""};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsCount(v2)));
}

TEST(hash, group_anagrams_single) {
    Solution49 sol;
    vector<string> v{"a"};
    auto expected = vector<vector<string>>{{"a"}};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsSort(v)));
    vector<string> v2{"a"};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsCount(v2)));
}

TEST(hash, group_anagrams_all_same) {
    Solution49 sol;
    vector<string> v{"abc", "bca", "cab"};
    auto expected = vector<vector<string>>{{"abc", "bca", "cab"}};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsSort(v)));
    vector<string> v2{"abc", "bca", "cab"};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsCount(v2)));
}

TEST(hash, group_anagrams_all_different) {
    Solution49 sol;
    vector<string> v{"a", "b", "c"};
    auto expected = vector<vector<string>>{{"a"}, {"b"}, {"c"}};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsSort(v)));
    vector<string> v2{"a", "b", "c"};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsCount(v2)));
}

TEST(hash, group_anagrams_mixed_lengths) {
    Solution49 sol;
    vector<string> v{"ab", "ba", "abc", "cba", "a"};
    auto expected = vector<vector<string>>{{"ab", "ba"}, {"abc", "cba"}, {"a"}};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsSort(v)));
    vector<string> v2{"ab", "ba", "abc", "cba", "a"};
    ASSERT_EQ(normalize(expected), normalize(sol.groupAnagramsCount(v2)));
}
