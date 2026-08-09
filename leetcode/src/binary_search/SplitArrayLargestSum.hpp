#pragma once

#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Binary search approach.
    // O(n * log(sum)) time, O(1) space.
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());  // O(n)
        long long hi = accumulate(nums.begin(), nums.end(), 0LL);  // O(n)

        // O(log(sum)) iterations
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canSplit(nums, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    // DP approach.
    // O(n^2 * k) time, O(n * k) space.
    int splitArrayDp(vector<int>& nums, int k) {
        int n = nums.size();
        // prefix[i] = sum of nums[0..i-1]
        vector<long long> prefix(n + 1, 0);
        // O(n)
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // dp[i][j] = min largest sum splitting nums[0..i-1] into j parts
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, LLONG_MAX));
        dp[0][0] = 0;

        // O(n * k) states
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                // O(n) transitions per state
                for (int m = j - 1; m < i; m++) {
                    long long cur = prefix[i] - prefix[m];
                    long long val = max(dp[m][j - 1], cur);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return (int)dp[n][k];
    }

private:
    // Check if we can split nums into at most k subarrays
    // each with sum <= maxSum.  O(n) time.
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int count = 1;
        long long curSum = 0;
        // O(n)
        for (int num : nums) {
            if (curSum + num > maxSum) {
                count++;
                curSum = num;
                if (count > k) return false;
            } else {
                curSum += num;
            }
        }
        return true;
    }
};
