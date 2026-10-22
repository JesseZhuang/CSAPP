#ifndef LEETCODE_DETERMINEIFTWOSTRINGSARECLOSE_HPP
#define LEETCODE_DETERMINEIFTWOSTRINGSARECLOSE_HPP

#include <algorithm>
#include <array>
#include <string>

class Solution {
public:
    bool closeStrings(const std::string &word1, const std::string &word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        std::array<int, 26> frequencies1{};
        std::array<int, 26> frequencies2{};
        for (char character : word1) {
            ++frequencies1[character - 'a'];
        }
        for (char character : word2) {
            ++frequencies2[character - 'a'];
        }

        for (int index = 0; index < 26; ++index) {
            if ((frequencies1[index] == 0) != (frequencies2[index] == 0)) {
                return false;
            }
        }

        std::sort(frequencies1.begin(), frequencies1.end());
        std::sort(frequencies2.begin(), frequencies2.end());
        return frequencies1 == frequencies2;
    }
};

#endif
