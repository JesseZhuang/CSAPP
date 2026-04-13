#ifndef LEETCODE_MINDISTANCETARGET_HPP
#define LEETCODE_MINDISTANCETARGET_HPP

#include <cmath>
#include <vector>

using namespace std;

// O(n) time, O(1) space
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res = min(res, abs(i - start));
            }
        }
        return res;
    }
};

#endif // LEETCODE_MINDISTANCETARGET_HPP
