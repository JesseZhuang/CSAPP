#ifndef COINCHANGEII_HPP
#define COINCHANGEII_HPP
#include <vector>

using namespace std;

// LeetCode 518. Coin Change II
// Given coins and an amount, return the number of combinations that make up that amount.
// Each coin may be used unlimited times.

// Solution 1: 1D DP. O(N*M) time, O(M) space. N: coins.size(), M: amount.
class CoinChangeII {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins)          // outer loop on coins avoids counting permutations
            for (int i = coin; i <= amount; i++)
                dp[i] += dp[i - coin];
        return dp[amount];
    }
};

// Solution 2: 2D DP. O(N*M) time, O(N*M) space.
// dp[i][j] = number of combinations using first i coins to make amount j.
class CoinChangeII2D {
public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        // dp[i][j]: combinations using coins[0..i-1] for amount j
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1; // one way to make amount 0: use no coins
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j]; // skip coin i
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]]; // use coin i
            }
        return dp[n][amount];
    }
};

#endif //COINCHANGEII_HPP
