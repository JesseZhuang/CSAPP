#ifndef LEETCODE_THREESUM_HPP
#define LEETCODE_THREESUM_HPP

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

// Solution 1: Sort + Two Pointers - Time O(n^2), Space O(1) excluding output
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        sort(nums.begin(), nums.end());         // O(n log n) sort for two-pointer scan

        for (int i = 0; i < n - 2; ++i) {      // O(n) fix first element
            if (nums[i] > 0) break;             // sorted: no triple can sum to 0
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate first element

            int left = i + 1, right = n - 1;   // O(1) two pointers for remaining pair
            while (left < right) {              // O(n) sweep per fixed element -> O(n^2) total
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;                     // need larger sum
                } else if (sum > 0) {
                    --right;                    // need smaller sum
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;   // skip duplicate second
                    while (left < right && nums[right] == nums[right - 1]) --right; // skip duplicate third
                    ++left;
                    --right;
                }
            }
        }
        return result;
    }
};

// Solution 2: Hash Set - Time O(n^2), Space O(n)
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        sort(nums.begin(), nums.end());         // O(n log n) sort to handle duplicates

        for (int i = 0; i < n - 2; ++i) {      // O(n) fix first element
            if (nums[i] > 0) break;             // sorted: no triple can sum to 0
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate first element

            unordered_set<int> seen;            // O(n) hash set for complement lookup
            for (int j = i + 1; j < n; ++j) {  // O(n) scan remaining elements
                int complement = -nums[i] - nums[j]; // target for third element
                if (seen.count(complement)) {
                    result.push_back({nums[i], complement, nums[j]});
                    while (j + 1 < n && nums[j] == nums[j + 1]) ++j; // skip duplicate third
                } else {
                    seen.insert(nums[j]);       // O(1) amortized insert
                }
            }
        }
        return result;
    }
};

#endif // LEETCODE_THREESUM_HPP
