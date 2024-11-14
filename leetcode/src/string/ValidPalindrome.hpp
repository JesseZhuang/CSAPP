#ifndef LEETCODE_VALIDPALINDROME_HPP
#define LEETCODE_VALIDPALINDROME_HPP

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (l < r && toupper(s[l]) != toupper(s[r])) return false;
        }
        return true;
    }
};

#endif //LEETCODE_VALIDPALINDROME_HPP
