#ifndef PALINDROMICSUBSTRINGS_HPP
#define PALINDROMICSUBSTRINGS_HPP
#include <string>
#include <utility>
#include "Manacher.hpp"

using namespace std;

// LeetCode 647, medium, tags: string, dynamic programming, two pointers.
class PalindromicSubstrings {
public:
    // Solution 1: Manacher's algorithm. O(n) time, O(n) space.
    static int countSubstringsManacher(string s) {
        Manacher m(move(s));
        return m.cntPalindromeSubstrings();
    }

    // Solution 2: Expand around center. O(n^2) time, O(1) space.
    static int countSubstrings(const string &s) {
        int count = 0;
        int n = static_cast<int>(s.size());
        for (int i = 0; i < n; i++) { // O(n) centers
            count += expand(s, i, i);
            count += expand(s, i, i + 1);
        }
        return count;
    }

private:
    // Each call O(n) worst case
    static int expand(const string &s, int l, int r) {
        int res = 0;
        int n = static_cast<int>(s.size());
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
            res++;
        }
        return res;
    }
};

#endif //PALINDROMICSUBSTRINGS_HPP
