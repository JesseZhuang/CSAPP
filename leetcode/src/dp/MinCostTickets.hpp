#ifndef MINCOSTTICKETS_HPP
#define MINCOSTTICKETS_HPP
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

// solution 1, DP on calendar days. O(lastDay) time, O(lastDay) space.
class MinCostTicketsDP {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int lastDay = days.back();
        unordered_set<int> travelDays(days.begin(), days.end());
        vector<int> dp(lastDay + 1, 0);
        for (int d = 1; d <= lastDay; d++) {
            if (travelDays.find(d) == travelDays.end()) {
                dp[d] = dp[d - 1];
            } else {
                dp[d] = min({dp[d - 1] + costs[0],
                             dp[max(0, d - 7)] + costs[1],
                             dp[max(0, d - 30)] + costs[2]});
            }
        }
        return dp[lastDay];
    }
};

// solution 2, DP on travel day indices with recursion+memo. O(n) time, O(n) space.
class MinCostTicketsMemo {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int n = days.size();
        vector<int> memo(n, -1);
        return solve(days, costs, 0, memo);
    }

private:
    int solve(vector<int> &days, vector<int> &costs, int i, vector<int> &memo) {
        if (i >= (int)days.size()) return 0;
        if (memo[i] != -1) return memo[i];
        // 1-day pass
        int res = costs[0] + solve(days, costs, i + 1, memo);
        // 7-day pass: find next day not covered
        int j = i;
        while (j < (int)days.size() && days[j] < days[i] + 7) j++;
        res = min(res, costs[1] + solve(days, costs, j, memo));
        // 30-day pass
        j = i;
        while (j < (int)days.size() && days[j] < days[i] + 30) j++;
        res = min(res, costs[2] + solve(days, costs, j, memo));
        return memo[i] = res;
    }
};

#endif //MINCOSTTICKETS_HPP
