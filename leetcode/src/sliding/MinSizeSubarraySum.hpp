#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// leet 209, sliding window, O(n) time, O(1) space
class SolutionMinSizeSubarraySum {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1;
        int sum = 0;
        for (int l = 0, r = 0; r < n; r++) {
            sum += nums[r];
            while (sum >= target) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l++];
            }
        }
        return minLen == n + 1 ? 0 : minLen;
    }
};

// leet 209, prefix sum + binary search, O(n log n) time, O(n) space
class SolutionMinSizeSubarraySum2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minLen = n + 1;
        for (int i = 0; i < n; i++) {
            // Find smallest j such that prefix[j] - prefix[i] >= target
            int needed = target + prefix[i];
            int low = i + 1, high = n + 1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (prefix[mid] < needed) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (low <= n) {
                minLen = min(minLen, low - i);
            }
        }
        return minLen == n + 1 ? 0 : minLen;
    }
};
