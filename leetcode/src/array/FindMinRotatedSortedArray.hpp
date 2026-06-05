#pragma once
#include <vector>
using namespace std;

// LeetCode 153 - Find Minimum in Rotated Sorted Array
class FindMinRotatedSortedArray {
public:
    // Solution 1: Binary search comparing mid with hi. O(log n) time, O(1) space.
    class Solution1 {
    public:
        int findMin(vector<int>& nums) {
            int lo = 0, hi = nums.size() - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] > nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            return nums[lo];
        }
    };

    // Solution 2: Binary search comparing mid with nums[0], early return if not rotated.
    class Solution2 {
    public:
        int findMin(vector<int>& nums) {
            int n = nums.size();
            // Not rotated (or single element)
            if (nums[0] <= nums[n - 1]) return nums[0];

            int lo = 0, hi = n - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] >= nums[0]) {
                    // mid is in the left sorted portion, min is to the right
                    lo = mid + 1;
                } else {
                    // mid is in the right sorted portion, min is at mid or left
                    hi = mid;
                }
            }
            return nums[lo];
        }
    };
};
