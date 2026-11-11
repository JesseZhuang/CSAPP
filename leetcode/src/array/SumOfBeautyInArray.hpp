#ifndef LEETCODE_SUMOFBEAUTYINARRAY_HPP
#define LEETCODE_SUMOFBEAUTYINARRAY_HPP

#include <algorithm>
#include <vector>

namespace SumOfBeautyInArray {

class Solution {
public:
    // Prefix maximum and suffix minima: O(n) time, O(n) extra space.
    int sumOfBeauties(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        std::vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = std::min(nums[i], suffixMin[i + 1]);
        }

        int prefixMax = nums[0];
        int beauty = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (prefixMax < nums[i] && nums[i] < suffixMin[i + 1]) {
                beauty += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ++beauty;
            }
            prefixMax = std::max(prefixMax, nums[i]);
        }
        return beauty;
    }
};

}

#endif
