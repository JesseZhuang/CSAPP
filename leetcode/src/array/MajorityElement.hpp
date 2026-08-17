#ifndef LEETCODE_MAJORITYELEMENT_HPP
#define LEETCODE_MAJORITYELEMENT_HPP

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Boyer-Moore Voting Algorithm: O(n) time, O(1) space
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }

    // Sort and return middle element: O(n log n) time
    int majorityElementSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

#endif //LEETCODE_MAJORITYELEMENT_HPP
