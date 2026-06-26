#pragma once
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// LeetCode 4 - Median of Two Sorted Arrays
class MedianTwoSortedArrays {
public:
    // Solution 1: Binary search on the shorter array. O(log(min(m,n))) time, O(1) space.
    class Solution1 {
    public:
        static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // Ensure nums1 is the shorter array for O(log(min(m,n))) complexity
            if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

            int m = nums1.size(), n = nums2.size();
            int lo = 0, hi = m; // Binary search bounds on partition of nums1
            int halfLen = (m + n + 1) / 2; // Left half size (ceiling for odd total)

            while (lo <= hi) {
                int i = lo + (hi - lo) / 2; // Partition index in nums1
                int j = halfLen - i;        // Partition index in nums2

                // Elements adjacent to the partition
                int maxLeftA  = (i == 0) ? INT_MIN : nums1[i - 1];
                int minRightA = (i == m) ? INT_MAX : nums1[i];
                int maxLeftB  = (j == 0) ? INT_MIN : nums2[j - 1];
                int minRightB = (j == n) ? INT_MAX : nums2[j];

                if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                    // Valid partition found
                    if ((m + n) % 2 == 1) {
                        return max(maxLeftA, maxLeftB); // Odd total: median is max of left
                    }
                    // Even total: average of max-left and min-right
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else if (maxLeftA > minRightB) {
                    hi = i - 1; // nums1 partition too far right
                } else {
                    lo = i + 1; // nums1 partition too far left
                }
            }
            return 0.0; // Should never reach here for valid input
        }
    };

    // Solution 2: Merge approach. O(m+n) time, O(m+n) space.
    class Solution2 {
    public:
        static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();
            vector<int> merged;
            merged.reserve(m + n); // O(m+n) space allocation

            // Standard merge of two sorted arrays — O(m+n) time
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (nums1[i] <= nums2[j]) merged.push_back(nums1[i++]);
                else merged.push_back(nums2[j++]);
            }
            while (i < m) merged.push_back(nums1[i++]);
            while (j < n) merged.push_back(nums2[j++]);

            int total = m + n;
            if (total % 2 == 1) {
                return merged[total / 2]; // Odd: middle element
            }
            // Even: average of two middle elements
            return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
        }
    };
};
