#ifndef PARTITIONEQUALSUBSETSUM_HPP
#define PARTITIONEQUALSUBSETSUM_HPP
#include <bitset>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums)
            for (int j = target; j >= num; j--)
                dp[j] = dp[j] || dp[j - num];
        return dp[target];
    }

    bool canPartition2(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        bitset<10001> dp;
        dp.set(0);
        for (int num : nums)
            dp |= (dp << num);
        return dp.test(target);
    }
};

#endif //PARTITIONEQUALSUBSETSUM_HPP
