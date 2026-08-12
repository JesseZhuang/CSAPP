#pragma once

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Sort + Binary Search on Answer + Greedy.
    // O(n log n + n log M) time where M = max - min, O(1) extra space.
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());  // O(n log n)
        int n = nums.size();

        int lo = 0;
        int hi = (n >= 2) ? nums[n - 1] - nums[0] : 0;

        // O(log M) iterations of binary search
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canFormPairs(nums, p, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    // Greedy check: can we form at least p pairs with max difference <= threshold?
    // O(n) time.
    bool canFormPairs(vector<int>& nums, int p, int threshold) {
        int count = 0;
        int i = 0;
        // O(n) scan
        while (i < (int)nums.size() - 1) {
            if (nums[i + 1] - nums[i] <= threshold) {  // take this pair
                count++;
                i += 2;  // skip both elements
            } else {
                i++;
            }
            if (count >= p) return true;  // early exit
        }
        return count >= p;
    }
};
