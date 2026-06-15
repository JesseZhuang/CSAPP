#pragma once

#include <vector>
#include <algorithm>

using namespace std;

// 31. Next Permutation https://leetcode.com/problems/next-permutation/
class NextPermutationSolution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        // Step 1: find pivot — rightmost element smaller than successor, O(n)
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {
            // Step 2: find rightmost element larger than pivot, O(n)
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        // Step 3: reverse suffix, O(n). Total: O(n) time, O(1) space
        reverse(nums.begin() + i + 1, nums.end());
    }
};
