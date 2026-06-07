#ifndef PERMUTATION_IN_STRING_HPP
#define PERMUTATION_IN_STRING_HPP

#include <algorithm>
#include <string>
using namespace std;

// leet 567, medium, tags: hash table, two pointers, string, sliding window.
// Approach 1: sliding window with match count. O(l2) time, O(1) space.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        int c1[26] = {}, c2[26] = {};
        for (int i = 0; i < m; ++i) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i < 26; ++i) if (c1[i] == c2[i]) matches++;
        for (int i = m; i < n; ++i) {
            if (matches == 26) return true;
            int idx = s2[i] - 'a';
            c2[idx]++;
            if (c2[idx] == c1[idx]) matches++;
            else if (c2[idx] == c1[idx] + 1) matches--;
            int lidx = s2[i - m] - 'a';
            c2[lidx]--;
            if (c2[lidx] == c1[lidx]) matches++;
            else if (c2[lidx] == c1[lidx] - 1) matches--;
        }
        return matches == 26;
    }
};

// Approach 2: sort and compare. O(l1*log(l1) * (l2-l1)) time, O(l1) space.
class Solution2 {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        sort(s1.begin(), s1.end());
        for (int i = 0; i <= n - m; ++i) {
            string sub = s2.substr(i, m);
            sort(sub.begin(), sub.end());
            if (sub == s1) return true;
        }
        return false;
    }
};

#endif
