#ifndef LEETCODE_FIRSTMISSINGPOSITIVE_HPP
#define LEETCODE_FIRSTMISSINGPOSITIVE_HPP

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// LeetCode 41 - First Missing Positive
// Given an unsorted integer array, find the smallest missing positive integer.
// Must run in O(n) time and use O(1) extra space.
class Solution41 {
public:
    // Approach 1: Cyclic sort — place value v at index v-1.
    // O(n) time, O(1) space.
    static int firstMissingPositive(vector<int> nums) {
        int n = static_cast<int>(nums.size());

        // Each element is swapped at most once to its correct position — O(n) total swaps.
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n
                   && nums[nums[i] - 1] != nums[i]) {  // O(1) amortized per element
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Linear scan to find first index where nums[i] != i+1 — O(n).
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }

    // Approach 2: Index marking with negation.
    // O(n) time, O(1) space.
    static int firstMissingPositiveMarking(vector<int> nums) {
        int n = static_cast<int>(nums.size());

        // Step 1: Replace non-positives and values > n with sentinel n+1 — O(n).
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: For each value v in [1, n], mark index v-1 as negative — O(n).
        for (int i = 0; i < n; ++i) {
            int val = abs(nums[i]);
            if (val <= n) {
                nums[val - 1] = -abs(nums[val - 1]);  // mark present
            }
        }

        // Step 3: First positive index means that index+1 is missing — O(n).
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};

#endif //LEETCODE_FIRSTMISSINGPOSITIVE_HPP
