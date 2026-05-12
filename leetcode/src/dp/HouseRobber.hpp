#ifndef HOUSEROBBER_HPP
#define HOUSEROBBER_HPP
#include <algorithm>
#include <vector>

using namespace std;

// solution 1, DP with two variables. O(N) time, O(1) space.
class HouseRobber {
public:
    int rob(vector<int> &nums) {
        int robPrev = 0, nRobPrev = 0;
        for (int n: nums) { // O(N)
            int robCur = nRobPrev + n;
            nRobPrev = max(nRobPrev, robPrev);
            robPrev = robCur;
        }
        return max(robPrev, nRobPrev);
    }
};

// solution 2, DP with array. O(N) time, O(N) space.
class HouseRobberDP {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n); // dp[i]: max money robbing from houses 0..i
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) // O(N)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp[n - 1];
    }
};

#endif //HOUSEROBBER_HPP
