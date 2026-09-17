#ifndef LEETCODE_FINDALLDUPLICATES_HPP
#define LEETCODE_FINDALLDUPLICATES_HPP

#include <vector>
#include <algorithm>

using namespace std;

// LeetCode 442 - Find All Duplicates in an Array
// Given an array of n integers where each integer is in [1, n]
// and each appears at most twice, return all integers that appear twice.
class Solution442 {
public:
    // Negation marking approach
    // O(n) time, O(1) space (output excluded)
    static vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int idx = abs(nums[i]) - 1;     // map value to index — O(1)
            if (nums[idx] < 0) {
                result.push_back(idx + 1);   // already visited → duplicate
            } else {
                nums[idx] = -nums[idx];      // mark as visited by negating
            }
        }
        return result;
    }

    // Cyclic sort approach: place each value v at index v-1
    // O(n) time (each element swapped at most once), O(1) space
    static vector<int> findDuplicatesCyclicSort(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        // Phase 1: cyclic sort — put nums[i] at position nums[i]-1
        for (int i = 0; i < n; i++) {
            while (nums[i] != nums[nums[i] - 1]) {  // swap until correct or duplicate — O(1) amortized
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // Phase 2: scan for mismatches — nums[i] != i+1 means duplicate
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {          // value at wrong position → it's a duplicate
                result.push_back(nums[i]);
            }
        }
        sort(result.begin(), result.end());   // ensure consistent ordering — O(k log k)
        return result;
    }
};

#endif //LEETCODE_FINDALLDUPLICATES_HPP
