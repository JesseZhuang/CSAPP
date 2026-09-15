#ifndef SUBARRAYSUMSDIVISIBLE_BY_K_HPP
#define SUBARRAYSUMSDIVISIBLE_BY_K_HPP

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /// Prefix sum + hash map with modular arithmetic. O(n) time, O(k) space.
    int subarraysDivByK(vector<int> &nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            int remainder = ((sum % k) + k) % k;
            if (prefixCount.count(remainder)) {
                count += prefixCount[remainder];
            }
            prefixCount[remainder]++;
        }
        return count;
    }

    /// Brute force. O(n^2) time, O(1) space.
    int subarraysDivByKBrute(vector<int> &nums, int k) {
        int count = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < (int)nums.size(); j++) {
                sum += nums[j];
                if (sum % k == 0) count++;
            }
        }
        return count;
    }
};

#endif
