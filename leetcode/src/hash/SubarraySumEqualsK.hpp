#ifndef SUBARRAYSUMEQUALS_K_HPP
#define SUBARRAYSUMEQUALS_K_HPP

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /// Prefix sum + hash map. O(n) time, O(n) space.
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            if (prefixCount.count(sum - k)) {
                count += prefixCount[sum - k];
            }
            prefixCount[sum]++;
        }
        return count;
    }

    /// Brute force. O(n^2) time, O(1) space.
    int subarraySumBrute(vector<int> &nums, int k) {
        int count = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < (int)nums.size(); j++) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;
    }
};

#endif
