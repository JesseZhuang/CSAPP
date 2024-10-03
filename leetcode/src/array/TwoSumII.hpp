#ifndef LEET_CODE_TWOSUMII_HPP
#define LEET_CODE_TWOSUMII_HPP

#include <vector>

using namespace std;

// lc 167
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) { // 12ms, 15.7Mb. two pointer.
        for (int l = 0, r = numbers.size() - 1; l < r;) {
            int add = numbers[l] + numbers[r];
            if (add > target) r--;
            else if (add < target) l++;
            else return {l + 1, r + 1}; // iterator will need cast to const, troublesome
        }
        return {};
    }
};

#endif //LEET_CODE_TWOSUMII_HPP
