#ifndef LONGESTINCREASINGSUBSEQUENCE_HPP
#define LONGESTINCREASINGSUBSEQUENCE_HPP
#include <algorithm>
#include <vector>

using namespace std;

// Solution 1: DP with binary search (patience sorting)
// Time: O(n log n), Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        // tails[i] = smallest tail element for increasing subsequence of length i+1
        vector<int> tails;
        // O(n) outer loop: process each element once
        for (int num : nums) {
            // O(log n) binary search for insertion point
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end())
                tails.push_back(num);
            else
                *it = num;
        }
        return tails.size();
    }
};

// Solution 2: Classic DP
// Time: O(n^2), Space: O(n)
class SolutionDP {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        // dp[i] = length of LIS ending at index i
        vector<int> dp(n, 1); // O(n) space
        int ans = 1;
        // O(n^2): for each element, check all previous elements
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

#endif //LONGESTINCREASINGSUBSEQUENCE_HPP
