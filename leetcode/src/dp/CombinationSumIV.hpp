#ifndef COMBINATIONSUMIV_HPP
#define COMBINATIONSUMIV_HPP
#include <vector>

using namespace std;

// solution 1, bottom-up DP. O(N*T) time, O(T) space. N: nums.size(), T: target.
class CombinationSumIVDP {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) // O(T)
            for (int num: nums) // O(N)
                if (i >= num)
                    dp[i] += dp[i - num];
        return (int) dp[target];
    }
};

// solution 2, top-down memoization. O(N*T) time, O(T) space.
class CombinationSumIVMemo {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> memo(target + 1, -1);
        return helper(nums, target, memo);
    }

private:
    int helper(vector<int> &nums, int remain, vector<int> &memo) {
        if (remain == 0) return 1;
        if (memo[remain] != -1) return memo[remain];
        int count = 0;
        for (int num: nums)
            if (remain >= num)
                count += helper(nums, remain - num, memo);
        return memo[remain] = count;
    }
};

#endif //COMBINATIONSUMIV_HPP
