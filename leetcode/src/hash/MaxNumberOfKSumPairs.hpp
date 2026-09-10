#ifndef MAX_NUMBER_OF_K_SUM_PAIRS_HPP
#define MAX_NUMBER_OF_K_SUM_PAIRS_HPP

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /// Hash map single-pass. O(n) time, O(n) space.
    int maxOperations(vector<int> &nums, int k) {
        unordered_map<int, int> freq;          // freq[v] = unseen count of v
        int ops = 0;
        for (int num : nums) {
            int complement = k - num;          // O(1) lookup for complement
            if (freq[complement] > 0) {
                freq[complement]--;            // consume one complement
                ops++;
            } else {
                freq[num]++;                   // store for future match
            }
        }
        return ops;
    }

    /// Sort + two pointers. O(n log n) time, O(1) extra space.
    int maxOperationsTwoPtr(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());        // O(n log n) sort
        int lo = 0, hi = (int)nums.size() - 1;
        int ops = 0;
        while (lo < hi) {                      // O(n) two-pointer scan
            int sum = nums[lo] + nums[hi];
            if (sum == k) {
                ops++;
                lo++;
                hi--;
            } else if (sum < k) {
                lo++;                          // need larger sum
            } else {
                hi--;                          // need smaller sum
            }
        }
        return ops;
    }
};

#endif
