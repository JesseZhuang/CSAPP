#include "gtest/gtest.h"
#include "string/CountPrefixAndSuffixPairsI.hpp"

#include <string>
#include <vector>

TEST(string, count_prefix_and_suffix_pairs_i_examples) {
    Solution3042 solution;
    std::vector<std::string> first{"a", "aba", "ababa", "aa"};
    std::vector<std::string> second{"pa", "papa", "ma", "mama"};
    std::vector<std::string> third{"abab", "ab"};
    EXPECT_EQ(4, solution.countPrefixSuffixPairs(first));
    EXPECT_EQ(2, solution.countPrefixSuffixPairs(second));
    EXPECT_EQ(0, solution.countPrefixSuffixPairs(third));
}

TEST(string, count_prefix_and_suffix_pairs_i_boundaries) {
    Solution3042 solution;
    std::vector<std::string> singleton{"a"};
    std::vector<std::string> duplicates{"abc", "abc", "abc"};
    std::vector<std::string> maximum(50, std::string(10, 'a'));
    EXPECT_EQ(0, solution.countPrefixSuffixPairs(singleton));
    EXPECT_EQ(3, solution.countPrefixSuffixPairs(duplicates));
    EXPECT_EQ(1225, solution.countPrefixSuffixPairs(maximum));
}

TEST(string, count_prefix_and_suffix_pairs_i_requires_both_ends) {
    Solution3042 solution;
    std::vector<std::string> prefix_only{"ab", "abcd"};
    std::vector<std::string> suffix_only{"cd", "abcd"};
    std::vector<std::string> longer_first{"abcd", "ab"};
    EXPECT_EQ(0, solution.countPrefixSuffixPairs(prefix_only));
    EXPECT_EQ(0, solution.countPrefixSuffixPairs(suffix_only));
    EXPECT_EQ(0, solution.countPrefixSuffixPairs(longer_first));
}
