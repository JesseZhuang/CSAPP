#ifndef LEETCODE_LARGESTSUBSTRINGBETWEENEQUALCHARACTERS_HPP
#define LEETCODE_LARGESTSUBSTRINGBETWEENEQUALCHARACTERS_HPP

#include <algorithm>
#include <array>
#include <string>

class Solution1624 {
public:
    // O(n) time and O(1) space because the input contains lowercase English letters.
    int maxLengthBetweenEqualCharacters(const std::string& s) {
        std::array<int, 26> firstOccurrence{};
        firstOccurrence.fill(-1);

        int longest = -1;
        for (int index = 0; index < static_cast<int>(s.size()); ++index) {
            const int character = s[index] - 'a';
            if (firstOccurrence[character] == -1) {
                firstOccurrence[character] = index;
            } else {
                longest = std::max(longest, index - firstOccurrence[character] - 1);
            }
        }
        return longest;
    }
};

#endif // LEETCODE_LARGESTSUBSTRINGBETWEENEQUALCHARACTERS_HPP
