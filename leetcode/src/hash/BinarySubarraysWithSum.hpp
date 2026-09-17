#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

// LeetCode 930 - Binary Subarrays With Sum
// Prefix sum approach
class Solution {
public:
    // O(n) time, O(n) space
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount; // prefix_sum -> count of occurrences
        prefixCount[0] = 1;                  // base case: empty prefix has sum 0
        int count = 0, sum = 0;
        for (int x : nums) {
            sum += x;
            if (prefixCount.count(sum - goal)) {
                count += prefixCount[sum - goal]; // number of prefixes that make subarray sum == goal
            }
            prefixCount[sum]++;
        }
        return count;
    }
};

// Sliding window approach: exactly(goal) = atMost(goal) - atMost(goal - 1)
class Solution2 {
public:
    // O(n) time, O(1) space
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int count = 0, sum = 0, left = 0;
        for (int right = 0; right < (int)nums.size(); ++right) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left++]; // shrink window until sum <= goal
            }
            count += right - left + 1; // all subarrays ending at right with sum <= goal
        }
        return count;
    }
};
