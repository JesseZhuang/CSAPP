#ifndef LONGEST_SUBSTRING_WITHOUT_REPEATING_HPP
#define LONGEST_SUBSTRING_WITHOUT_REPEATING_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// leet code 3
class LongestSubstringWithoutRepeating {
public:
    // solution 1: sliding window with hash map. O(n) time, O(min(n,m)) space.
    static int lengthOfLongestSubstring(const string& s) {
        unordered_map<char, int> lastSeen;
        int maxLen = 0;
        for (int left = 0, right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            if (lastSeen.count(c) && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }
            lastSeen[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // solution 2: sliding window with hash set. O(n) time, O(min(n,m)) space.
    static int lengthOfLongestSubstring2(const string& s) {
        unordered_set<char> window;
        int maxLen = 0;
        for (int left = 0, right = 0; right < (int)s.size(); ++right) {
            while (window.count(s[right])) {
                window.erase(s[left]);
                ++left;
            }
            window.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

#endif
