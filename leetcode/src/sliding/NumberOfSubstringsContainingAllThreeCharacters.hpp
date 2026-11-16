#pragma once
#include <algorithm>
#include <string>

using namespace std;

// LeetCode 1358: Number of Substrings Containing All Three Characters
class SolutionNumberOfSubstringsContainingAllThreeCharacters {
public:
    // Last-seen indices. O(n) time, O(1) extra space.
    int numberOfSubstrings(const string& s) {
        int lastSeen[3] = {-1, -1, -1};
        int total = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            lastSeen[s[right] - 'a'] = right;
            // Every start through the earliest last-seen index is valid.
            total += min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1;
        }
        return total;
    }

    // Each endpoint advances at most n times: O(n) time, O(1) extra space.
    int numberOfSubstringsSlidingWindow(const string& s) {
        int counts[3] = {0, 0, 0};
        int left = 0, total = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            ++counts[s[right] - 'a'];
            while (counts[0] > 0 && counts[1] > 0 && counts[2] > 0) {
                --counts[s[left] - 'a'];
                ++left;
            }
            // Starts before left form all valid substrings ending at right.
            total += left;
        }
        return total;
    }
};
