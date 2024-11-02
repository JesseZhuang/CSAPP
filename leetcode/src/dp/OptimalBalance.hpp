#ifndef LEETCODE_OPTIMALBALANCE_HPP
#define LEETCODE_OPTIMALBALANCE_HPP

#include <vector>
#include <unordered_map>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>> &transactions) {
        int g[12]{};
        for (auto &t: transactions) {
            g[t[0]] -= t[2];
            g[t[1]] += t[2];
        }
        vector<int> nums;
        for (int x: g)
            if (x) nums.push_back(x);
        int m = nums.size();
        int f[1 << m];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < 1 << m; ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j)
                if (i >> j & 1) s += nums[j];
            if (s == 0) {
                f[i] = __builtin_popcount(i) - 1;
                for (int j = (i - 1) & i; j; j = (j - 1) & i)
                    f[i] = min(f[i], f[j] + f[i ^ j]);
            }
        }
        return f[(1 << m) - 1];
    }
};

class Solution2 {
public:
    int minTransfers(vector<vector<int>> &transactions) {
        unordered_map<int, int> bal;

        for (const auto &e: transactions) {
            int f = e[0], t = e[1], amount = e[2];
            bal[f] -= amount;
            bal[t] += amount;
        }
        // Step 2: Filter out zero balances and store non-zero balances
        vector<int> balances;
        for (const auto &entry: bal)
            if (entry.second != 0)
                balances.push_back(entry.second);
        // Step 3: Use backtracking to find the minimum transactions
        return dfs(balances, 0);
    }

private:
    int dfs(vector<int> &balances, int start) {
        int n = balances.size();
        // Skip settled (zero) balances
        while (start < n && balances[start] == 0) ++start;
        // Base case: All balances settled
        if (start == n) return 0;
        int res = INT_MAX;
        for (int i = start + 1; i < n; ++i) {
            if (balances[i] * balances[start] < 0) {  // Check opposite signs
                // Settle balances[start] with balances[i]
                balances[i] += balances[start];
                res = min(res, 1 + dfs(balances, start + 1));
                // Backtrack
                balances[i] -= balances[start];
            }
        }

        return res;
    }
};


#endif //LEETCODE_OPTIMALBALANCE_HPP
