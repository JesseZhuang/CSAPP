#ifndef LEETCODE_TWOSUM_HPP
#define LEETCODE_TWOSUM_HPP

#include <unordered_map>
#include <vector>

using namespace std;

// apple clang 16 does not support views::enumerate
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> valInd;
        for (int i = 0; i < nums.size(); i++) {
            int look = target - nums[i];
            if (valInd.count(look)) return {i, valInd[look]};
            valInd[nums[i]] = i;
        }
        throw runtime_error("not found");
    }
};

#endif //LEETCODE_TWOSUM_HPP
