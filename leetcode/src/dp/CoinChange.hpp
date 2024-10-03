#ifndef COINCHANGE_HPP
#define COINCHANGE_HPP
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int c: coins)
            for (int i = c; i <= amount; i++)
                if (dp[i - c] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - c] + 1);
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


#endif //COINCHANGE_HPP
