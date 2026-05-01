#ifndef MAXIMUM_SUBARRAY_HPP
#define MAXIMUM_SUBARRAY_HPP

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

/// LeetCode 53 / LintCode 41, medium, tags: array, divide and conquer, dp, prefix sum.
class SolutionMaximumSubarray {
public:
    /// Kadane DP: track max sum ending at current index. Time O(n), Space O(1).
    int maxSubArrayDP(const vector<int>& nums) {
        int maxHere = 0, res = INT_MIN;
        for (int n : nums) {
            maxHere = max(n, maxHere + n);  // restart at n if running sum hurts
            res = max(res, maxHere);
        }
        return res;
    }

    /// Divide and conquer with prefix/suffix arrays. Time O(n), Space O(n).
    int maxSubArrayDnC(const vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return INT_MIN;
        vector<int> pre(nums.begin(), nums.end());
        vector<int> suf(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) pre[i] += max(0, pre[i - 1]);
        for (int i = n - 2; i >= 0; --i) suf[i] += max(0, suf[i + 1]);
        return dncHelper(nums, pre, suf, 0, n - 1);
    }

private:
    int dncHelper(const vector<int>& nums, const vector<int>& pre, const vector<int>& suf,
                  int left, int right) {
        if (left == right) return nums[left];
        int mid = (left + right) / 2;
        int leftBest = dncHelper(nums, pre, suf, left, mid);
        int rightBest = dncHelper(nums, pre, suf, mid + 1, right);
        int crossBest = pre[mid] + suf[mid + 1];
        return max({leftBest, rightBest, crossBest});
    }
};

#endif
