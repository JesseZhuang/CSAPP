#ifndef SINGLEELEMENTSORTED_HPP
#define SINGLEELEMENTSORTED_HPP
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == nums[m ^ 1]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};


#endif //SINGLEELEMENTSORTED_HPP
