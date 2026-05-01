#ifndef COINCHANGE_HPP
#define COINCHANGE_HPP
#include <climits>
#include <queue>
#include <vector>

using namespace std;

// solution 1, DP. O(N*M) time, O(M) space. N: coins.size(), M: amount.
class CoinChangeDP {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int c: coins) // O(N)
            for (int i = c; i <= amount; i++) // O(M)
                if (dp[i - c] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - c] + 1);
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// solution 2, BFS shortest path. O(N*M) time, O(M) space.
class CoinChangeBFS {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        vector<bool> visited(amount + 1, false);
        queue<int> q;
        q.push(amount);
        visited[amount] = true;
        int count = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) { // O(level size)
                int cur = q.front();
                q.pop();
                if (cur == 0) return count;
                for (int coin: coins) { // O(N)
                    int nxt = cur - coin;
                    if (nxt >= 0 && !visited[nxt]) {
                        q.push(nxt);
                        visited[nxt] = true;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};

#endif //COINCHANGE_HPP
