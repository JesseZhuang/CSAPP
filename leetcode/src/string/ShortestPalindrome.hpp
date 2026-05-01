#ifndef LEETCODE_SHORTESTPALINDROME_HPP
#define LEETCODE_SHORTESTPALINDROME_HPP

#include <string>
#include <algorithm>

using namespace std;

// leet 214, rolling hash. O(n) time, O(n) space.
class Solution214 {
public:
    string shortestPalindrome(string s) {
        long long base = 31, pw = 1, mod = 1e9 + 7;
        long long forward = 0, reverse = 0;
        int end = -1;
        for (int i = 0; i < (int) s.size(); i++) {
            int id = s[i] - 'a' + 1;
            forward = (forward * base + id) % mod;
            reverse = (reverse + (long long) id * pw) % mod;
            pw = (pw * base) % mod;
            if (forward == reverse) end = i;
        }
        string suffix = s.substr(end + 1);
        string rev_suffix(suffix.rbegin(), suffix.rend());
        return rev_suffix + s;
    }
};

#endif //LEETCODE_SHORTESTPALINDROME_HPP
