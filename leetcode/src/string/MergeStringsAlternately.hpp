#ifndef LEETCODE_MERGE_STRINGS_ALTERNATELY_HPP
#define LEETCODE_MERGE_STRINGS_ALTERNATELY_HPP

#include <string>

class Solution1768 {
public:
    // O(m + n) time and O(1) auxiliary space, excluding the O(m + n) result.
    std::string mergeAlternately(const std::string& word1, const std::string& word2) {
        std::string merged;
        merged.reserve(word1.size() + word2.size());
        std::size_t first = 0;
        std::size_t second = 0;
        while (first < word1.size() || second < word2.size()) {
            if (first < word1.size()) merged += word1[first++];
            if (second < word2.size()) merged += word2[second++];
        }
        return merged;
    }
};

#endif // LEETCODE_MERGE_STRINGS_ALTERNATELY_HPP
