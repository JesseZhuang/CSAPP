#ifndef PALINDROMICSUBSTRINGS_HPP
#define PALINDROMICSUBSTRINGS_HPP
#include <string>
#include <utility>
#include "Manacher.hpp"

using namespace std;

// LeetCode 647, medium
class Solution {
public:
    int countSubstrings(string s) {
        Manacher m(std::move(s));
        return m.cntPalindromeSubstrings();
    }
};

#endif //PALINDROMICSUBSTRINGS_HPP
