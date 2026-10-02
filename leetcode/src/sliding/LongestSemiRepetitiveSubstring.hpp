#pragma once

#include <algorithm>
#include <string>

using namespace std;

// LeetCode 2730: Find the Longest Semi-Repetitive Substring
// Sliding window approach, O(n) time, O(1) space.
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int equalPairs = 0;
        int longest = 0;

        // Each character enters the window once, so the expansion is O(n).
        for (int left = 0, right = 0; right < (int)s.size(); right++) {
            if (right > 0 && s[right] == s[right - 1]) {
                equalPairs++;
            }

            // Each character leaves the window at most once, so shrinking is O(n).
            while (equalPairs > 1) {
                if (left + 1 <= right && s[left] == s[left + 1]) {
                    equalPairs--;
                }
                left++;
            }

            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
