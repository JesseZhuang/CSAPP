#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class ContiguousArray {
public:
    // O(n) time, O(n) space
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixIndex; // prefix_sum -> earliest index
        prefixIndex[0] = -1;                 // base case: sum 0 at virtual index -1
        int maxLen = 0, sum = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += (nums[i] == 0 ? -1 : 1); // treat 0 as -1, running prefix sum
            if (prefixIndex.count(sum)) {
                maxLen = max(maxLen, i - prefixIndex[sum]); // subarray between has equal 0s and 1s
            } else {
                prefixIndex[sum] = i;        // record first occurrence
            }
        }
        return maxLen;
    }
};
