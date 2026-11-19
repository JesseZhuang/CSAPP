#ifndef LEETCODE_CHECKVALIDPARTITION_HPP
#define LEETCODE_CHECKVALIDPARTITION_HPP

#include <vector>

namespace check_valid_partition {

class Solution {
public:
    // LeetCode 2369. O(n) time and O(1) auxiliary space.
    bool validPartition(std::vector<int> &nums) {
        bool dp0 = true;
        bool dp1 = false;
        bool dp2 = nums[0] == nums[1];
        const int n = static_cast<int>(nums.size());

        // Before each iteration these hold dp[i - 3], dp[i - 2], dp[i - 1].
        for (int i = 3; i <= n; ++i) {
            const bool equalPair = nums[i - 2] == nums[i - 1];
            const bool equalTriple = equalPair && nums[i - 3] == nums[i - 2];
            const bool increasingTriple = nums[i - 3] + 1 == nums[i - 2]
                                          && nums[i - 2] + 1 == nums[i - 1];
            const bool current = (dp1 && equalPair)
                                 || (dp0 && (equalTriple || increasingTriple));
            dp0 = dp1;
            dp1 = dp2;
            dp2 = current;
        }
        return dp2;
    }
};

} // namespace check_valid_partition

#endif // LEETCODE_CHECKVALIDPARTITION_HPP
