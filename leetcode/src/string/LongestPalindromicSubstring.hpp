#ifndef LEETCODE_LONGESTPALINDROMICSUBSTRING_HPP
#define LEETCODE_LONGESTPALINDROMICSUBSTRING_HPP

#include <string>
#include <vector>

using namespace std;

// leet 5, expand from center. O(n^2) time, O(1) space.
class Solution5 {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size(), start = 0, maxLen = 1;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
            if (r - l - 1 > maxLen) {
                start = l + 1;
                maxLen = r - l - 1;
            }
        };
        for (int i = 0; i < n; i++) {
            expand(i, i);     // odd length
            expand(i, i + 1); // even length
        }
        return s.substr(start, maxLen);
    }
};

// leet 5, Manacher's algorithm. O(n) time, O(n) space.
class Solution5Manacher {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size();
        if (n == 0) return "";
        // transform: $#a#b#c#@
        string t = "$#";
        for (char c: s) { t += c; t += '#'; }
        t += '@';
        int m = (int) t.size();
        vector<int> p(m, 0);
        int center = 0, right = 0;
        for (int i = 1; i < m - 1; i++) {
            int mirror = 2 * center - i;
            if (right > i) p[i] = min(right - i, p[mirror]);
            while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
            if (i + p[i] > right) { center = i; right = i + p[i]; }
        }
        int maxLen = 0, maxCenter = 0;
        for (int i = 1; i < m - 1; i++) {
            if (p[i] > maxLen) { maxLen = p[i]; maxCenter = i; }
        }
        int origStart = (maxCenter - 1 - maxLen) / 2;
        return s.substr(origStart, maxLen);
    }
};

#endif //LEETCODE_LONGESTPALINDROMICSUBSTRING_HPP
