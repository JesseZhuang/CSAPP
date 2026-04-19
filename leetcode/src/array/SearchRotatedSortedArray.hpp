#ifndef LEETCODE_SEARCHROTATEDSORTEDARRAY_HPP
#define LEETCODE_SEARCHROTATEDSORTEDARRAY_HPP

#include <vector>

using namespace std;

// leet 33, medium, tags: array, binary search.
// Solution 1: single-pass modified binary search, O(log n) time, O(1) space.
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = (int) nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[l] <= nums[m]) { // left sorted
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            } else { // right sorted
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }
};

// Solution 2: two-pass, find pivot then binary search, O(log n) time, O(1) space.
class Solution2 {
public:
    int search(vector<int> &nums, int target) {
        int n = (int) nums.size();
        // find the index of the minimum element (pivot)
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        int pivot = l;
        // binary search in the correct half
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            l = pivot;
            r = n - 1;
        } else {
            l = 0;
            r = pivot - 1;
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};

#endif //LEETCODE_SEARCHROTATEDSORTEDARRAY_HPP
