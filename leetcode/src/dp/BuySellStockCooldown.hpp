#ifndef BUY_SELL_STOCK_COOLDOWN_HPP
#define BUY_SELL_STOCK_COOLDOWN_HPP

#include <algorithm>
#include <vector>

using namespace std;

/// LeetCode 309, medium, tags: array, dp.
class SolutionBuySellStockCooldown {
public:
    /// State machine DP. Three states: hold, sold, rest. Time O(n), Space O(1).
    static int maxProfitStateMachine(const vector<int>& prices) {
        int hold = INT_MIN, sold = 0, rest = 0;
        for (int p : prices) {
            int prevSold = sold;
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, prevSold);
        }
        return max(sold, rest);
    }

    /// DP arrays: buy[i], sell[i]. Time O(n), Space O(n).
    static int maxProfitDPArray(const vector<int>& prices) {
        int n = (int)prices.size();
        if (n < 2) return 0;
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = max(buy[0], -prices[1]);
        sell[1] = max(sell[0], buy[0] + prices[1]);
        for (int i = 2; i < n; ++i) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[n - 1];
    }
};

#endif
