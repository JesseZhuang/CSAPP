#ifndef LEETCODE_MINIMUMOPERATIONSTOMAKEARRAYINCREASING_HPP
#define LEETCODE_MINIMUMOPERATIONSTOMAKEARRAYINCREASING_HPP

#include <algorithm>
#include <cstddef>
#include <vector>

namespace MinimumOperationsToMakeArrayIncreasing {

class Solution {
public:
    // Greedy pass: O(n) time, O(1) extra space.
    int minOperations(const std::vector<int>& nums) {
        int previous = nums[0];
        int operations = 0;
        for (std::size_t index = 1; index < nums.size(); ++index) {
            const int original = nums[index];
            const int adjusted = std::max(original, previous + 1);
            operations += adjusted - original;
            previous = adjusted;
        }
        return operations;
    }
};

}

#endif
