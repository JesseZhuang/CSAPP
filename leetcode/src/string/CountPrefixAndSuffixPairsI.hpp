#ifndef LEETCODE_COUNT_PREFIX_AND_SUFFIX_PAIRS_I_HPP
#define LEETCODE_COUNT_PREFIX_AND_SUFFIX_PAIRS_I_HPP

#include <string>
#include <vector>

class Solution3042 {
public:
    int countPrefixSuffixPairs(const std::vector<std::string>& words) {
        int count = 0;
        // O(n^2) pairs, with O(L) comparisons and O(1) auxiliary space.
        for (std::size_t i = 0; i < words.size(); ++i) {
            for (std::size_t j = i + 1; j < words.size(); ++j) {
                const std::string& prefix = words[i];
                const std::string& word = words[j];
                if (prefix.size() <= word.size() &&
                    word.compare(0, prefix.size(), prefix) == 0 &&
                    word.compare(word.size() - prefix.size(), prefix.size(), prefix) == 0) {
                    ++count;
                }
            }
        }
        return count;
    }
};

#endif // LEETCODE_COUNT_PREFIX_AND_SUFFIX_PAIRS_I_HPP
