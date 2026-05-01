#ifndef LEETCODE_CONSTRUCTKPALINDROMESTRINGS_HPP
#define LEETCODE_CONSTRUCTKPALINDROMESTRINGS_HPP

#include <string>

using namespace std;

// leet 1400, O(n) time, O(1) space.
class ConstructKPalindromeStrings {
public:
    bool canConstruct(const string &s, int k) {
        int n = (int) s.size();
        if (n < k) return false;
        if (n == k) return true;
        int cnt[26] = {};
        for (char c: s) cnt[c - 'a']++;
        int odd = 0;
        for (int c: cnt) if (c & 1) odd++;
        return odd <= k;
    }
};

#endif //LEETCODE_CONSTRUCTKPALINDROMESTRINGS_HPP
