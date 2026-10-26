#ifndef LEETCODE_REVERSE_PREFIX_OF_WORD_HPP
#define LEETCODE_REVERSE_PREFIX_OF_WORD_HPP

#include <string>
#include <utility>

class Solution2000 {
public:
    std::string reversePrefix(std::string word, char ch) {
        const std::size_t end = word.find(ch);
        if (end == std::string::npos) return word;

        for (std::size_t left = 0, right = end; left < right; ++left, --right) {
            std::swap(word[left], word[right]);
        }
        return word;
    }
};

#endif // LEETCODE_REVERSE_PREFIX_OF_WORD_HPP
