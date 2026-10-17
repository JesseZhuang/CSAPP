#ifndef LEETCODE_LONGESTSUBARRAYWITHMAXIMUMBITWISEAND_HPP
#define LEETCODE_LONGESTSUBARRAYWITHMAXIMUMBITWISEAND_HPP

#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int maximum = nums[0];
        int currentStreak = 0;
        int bestStreak = 0;

        // One scan: O(n) time, O(1) space.
        for (int value : nums) {
            if (value > maximum) {
                maximum = value;
                currentStreak = 1;
                bestStreak = 1;
            } else if (value == maximum) {
                ++currentStreak;
                if (currentStreak > bestStreak) bestStreak = currentStreak;
            } else {
                currentStreak = 0;
            }
        }

        return bestStreak;
    }
};

#endif
