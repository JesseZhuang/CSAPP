#ifndef SINGLEESORTED_HPP
#define SINGLEESORTED_HPP
#include <vector>

using namespace std;

// LeetCode 540

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == nums[mid ^ 1]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};

#endif //SINGLEESORTED_HPP
