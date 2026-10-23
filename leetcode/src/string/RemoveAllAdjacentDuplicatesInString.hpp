#ifndef LEETCODE_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_HPP
#define LEETCODE_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_HPP

#include <string>

class Solution1047 {
public:
    // Time: O(n); space: O(n) for the string used as a stack.
    std::string removeDuplicates(std::string s) {
        std::string result;
        result.reserve(s.size());
        for (char character : s) {
            if (!result.empty() && result.back() == character) {
                result.pop_back();
            } else {
                result.push_back(character);
            }
        }
        return result;
    }
};

#endif // LEETCODE_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_HPP
