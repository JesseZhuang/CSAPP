#ifndef RUNNINGSUMOF1DARRAY_HPP
#define RUNNINGSUMOF1DARRAY_HPP

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (size_t index = 1; index < nums.size(); ++index) {
            nums[index] += nums[index - 1];
        }
        return nums;
    }
};

#endif // RUNNINGSUMOF1DARRAY_HPP
