#pragma once
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

// LeetCode 1208: Get Equal Substrings Within Budget
class SolutionEqualSubstringWithinBudget {
public:
    // Sliding window. O(n) time, O(1) extra space.
    int equalSubstring(const string& s, const string& t, int maxCost) {
        int left = 0, cost = 0, longest = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cost += abs(s[right] - t[right]);
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                ++left;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
