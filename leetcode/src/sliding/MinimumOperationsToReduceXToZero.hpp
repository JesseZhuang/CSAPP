#pragma once
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class SolutionMinimumOperationsToReduceXToZero {
public:
    // LeetCode 1658: keep the longest window summing to total - x.
    // Positive elements allow a sliding window: O(n) time, O(1) extra space.
    static int minOperations(const vector<int>& nums, int x) {
        const int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;

        const int n = static_cast<int>(nums.size());
        int left = 0, sum = 0, longest = target == 0 ? 0 : -1;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (left <= right && sum > target) sum -= nums[left++];
            if (sum == target) longest = max(longest, right - left + 1);
        }
        return longest < 0 ? -1 : n - longest;
    }

    // Keep the earliest index of each prefix to maximize the retained window.
    // O(n) expected time, O(n) extra space.
    static int minOperationsByPrefixSum(const vector<int>& nums, int x) {
        const int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;

        const int n = static_cast<int>(nums.size());
        unordered_map<int, int> earliest{{0, -1}};
        int prefix = 0, longest = target == 0 ? 0 : -1;
        for (int i = 0; i < n; ++i) {
            prefix += nums[i];
            auto found = earliest.find(prefix - target);
            if (found != earliest.end()) longest = max(longest, i - found->second);
            earliest.emplace(prefix, i);
        }
        return longest < 0 ? -1 : n - longest;
    }
};
