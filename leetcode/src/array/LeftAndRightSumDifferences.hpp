#ifndef LEFTANDRIGHTSUMDIFFERENCES_HPP
#define LEFTANDRIGHTSUMDIFFERENCES_HPP

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int right = 0;
        for (int num : nums) {
            right += num;
        }

        int left = 0;
        vector<int> result(nums.size());
        for (size_t index = 0; index < nums.size(); ++index) {
            right -= nums[index];
            result[index] = abs(left - right);
            left += nums[index];
        }
        return result;
    }
};

#endif // LEFTANDRIGHTSUMDIFFERENCES_HPP
