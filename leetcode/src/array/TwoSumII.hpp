#ifndef LEET_CODE_TWOSUMII_HPP
#define LEET_CODE_TWOSUMII_HPP

#include <algorithm>
#include <vector>

using namespace std;

// lc 167
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) { // 12ms, 15.7Mb. two pointer. O(n) time, O(1) space.
        for (int l = 0, r = numbers.size() - 1; l < r;) {
            int add = numbers[l] + numbers[r];
            if (add > target) r--;
            else if (add < target) l++;
            else return {l + 1, r + 1}; // iterator will need cast to const, troublesome
        }
        return {};
    }

    // Binary search approach: for each element, binary search for complement in the remaining range.
    // O(n log n) time, O(1) space.
    vector<int> twoSumBS(vector<int> &numbers, int target) {
        for (int i = 0; i < (int)numbers.size(); i++) {
            int complement = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), complement);
            if (it != numbers.end() && *it == complement) {
                return {i + 1, (int)(it - numbers.begin()) + 1};
            }
        }
        return {};
    }
};

#endif //LEET_CODE_TWOSUMII_HPP
