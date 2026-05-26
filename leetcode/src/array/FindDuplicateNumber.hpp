#ifndef LEETCODE_FINDDUPLICATENUMBER_HPP
#define LEETCODE_FINDDUPLICATENUMBER_HPP

#include <vector>

using namespace std;

// LeetCode 287 - Find the Duplicate Number
// Given an array of n+1 integers where each integer is in [1, n],
// find the one duplicate number.
class Solution287 {
public:
    // Floyd's cycle detection (tortoise and hare)
    // O(n) time, O(1) space
    static int findDuplicate(vector<int>& nums) {
        int slow = nums[0];          // tortoise starts at nums[0]
        int fast = nums[0];          // hare starts at nums[0]

        // Phase 1: find intersection point in the cycle
        do {
            slow = nums[slow];       // move one step
            fast = nums[nums[fast]]; // move two steps — O(1) per iteration
        } while (slow != fast);      // guaranteed to meet inside cycle

        // Phase 2: find entrance to the cycle (the duplicate value)
        slow = nums[0];              // reset slow to start
        while (slow != fast) {
            slow = nums[slow];       // both move one step
            fast = nums[fast];       // distance to entrance is equal from both
        }
        return slow;                 // entrance = duplicate number
    }

    // Binary search on value range [1, n]
    // O(n log n) time, O(1) space
    static int findDuplicate2(vector<int>& nums) {
        int lo = 1;                              // lower bound of value range
        int hi = static_cast<int>(nums.size()) - 1; // upper bound = n

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;        // pivot value — O(1)
            int count = 0;
            for (int num : nums) {               // count elements <= mid — O(n) per iteration
                if (num <= mid) count++;
            }
            // By pigeonhole: if count > mid, duplicate is in [lo, mid]
            if (count > mid) {
                hi = mid;                        // duplicate in lower half
            } else {
                lo = mid + 1;                    // duplicate in upper half
            }
        }                                        // O(log n) iterations total
        return lo;
    }
};

#endif //LEETCODE_FINDDUPLICATENUMBER_HPP
