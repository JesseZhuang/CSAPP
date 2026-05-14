#ifndef BUY_SELL_STOCK_HPP
#define BUY_SELL_STOCK_HPP

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

/// LeetCode 121, easy, tags: array, dp.
class SolutionBuySellStock {
public:
    /// One pass tracking min price seen so far. Time O(n), Space O(1).
    int maxProfitMinPrice(const vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for (int p : prices) {
            minPrice = min(minPrice, p);
            maxProfit = max(maxProfit, p - minPrice);
        }
        return maxProfit;
    }

    /// Kadane's algorithm on daily price changes. Time O(n), Space O(1).
    int maxProfitKadane(const vector<int>& prices) {
        int maxProfit = 0, curMax = 0;
        for (int i = 1; i < (int)prices.size(); ++i) {
            curMax = max(0, curMax + prices[i] - prices[i - 1]);
            maxProfit = max(maxProfit, curMax);
        }
        return maxProfit;
    }
};

#endif
