#pragma once
#include <algorithm>
#include <vector>

using namespace std;

// LeetCode 1493: Longest Subarray of 1's After Deleting One Element
class SolutionLongestSubarrayOfOnesAfterDeletingOneElement {
public:
    // One-zero sliding window. O(n) time, O(1) space.
    int longestSubarray(vector<int> &nums) {
        int left = 0, zeros = 0, longest = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            if (nums[right] == 0) ++zeros;
            while (zeros > 1) {
                if (nums[left] == 0) --zeros;
                ++left;
            }
            longest = max(longest, right - left);
        }
        return longest;
    }
};

class SolutionLongestSubarrayOfOnesAfterDeletingOneElement2 {
public:
    // Prefix/suffix counts around each deleted element. O(n) time, O(n) space.
    int longestSubarray(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) prefix[i] = 1 + (i > 0 ? prefix[i - 1] : 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 1) suffix[i] = 1 + (i + 1 < n ? suffix[i + 1] : 0);
        }

        int longest = 0;
        for (int i = 0; i < n; i++) {
            int onesBefore = i > 0 ? prefix[i - 1] : 0;
            int onesAfter = i + 1 < n ? suffix[i + 1] : 0;
            longest = max(longest, onesBefore + onesAfter);
        }
        return longest;
    }
};
