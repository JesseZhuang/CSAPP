#pragma once
#include <vector>

using namespace std;

// leet 1004, sliding window. O(n) time, O(1) space.
class SolutionMaxConsecutiveOnesIII {
public:
    int longestOnes(vector<int> &nums, int k) {
        int l = 0, r = 0, n = nums.size();
        while (r < n) {
            if (nums[r++] == 0) --k;
            if (k < 0 && nums[l++] == 0) ++k;
        }
        return r - l;
    }
};

// leet 1004, binary search + prefix sum. O(n log n) time, O(n) space.
class SolutionMaxConsecutiveOnesIII2 {
public:
    int longestOnes(vector<int> &nums, int k) {
        int n = nums.size();
        // prefix[i] = number of zeros in nums[0..i-1]
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + (nums[i] == 0);

        int lo = 0, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // check if a window of size mid exists with at most k zeros
            bool found = false;
            for (int i = 0; i + mid <= n; ++i) {
                if (prefix[i + mid] - prefix[i] <= k) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
