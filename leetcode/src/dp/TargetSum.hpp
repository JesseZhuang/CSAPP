#ifndef TARGETSUM_HPP
#define TARGETSUM_HPP
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// solution 1, Subset Sum DP. O(n*P) time, O(P) space. P=(total+target)/2.
class TargetSumDP {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total || (total + target) % 2 != 0) return 0;
        int P = (total + target) / 2;
        vector<int> dp(P + 1, 0);
        dp[0] = 1;
        for (int num : nums)           // O(n)
            for (int j = P; j >= num; j--) // O(P)
                dp[j] += dp[j - num];
        return dp[P];
    }
};

// solution 2, DFS + memoization. O(n*s) time, O(n*s) space. s=sum range.
class TargetSumDFS {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total || (total + target) % 2 != 0) return 0;
        unordered_map<long, int> memo;
        return dfs(nums, 0, target, memo);
    }

private:
    int dfs(vector<int>& nums, int idx, int remain, unordered_map<long, int>& memo) {
        if (idx == (int)nums.size()) return remain == 0 ? 1 : 0;
        long key = (long)idx * 100001 + remain + 50000; // encode (idx, remain)
        if (memo.count(key)) return memo[key];
        int res = dfs(nums, idx + 1, remain - nums[idx], memo)
                + dfs(nums, idx + 1, remain + nums[idx], memo);
        return memo[key] = res;
    }
};

#endif //TARGETSUM_HPP
