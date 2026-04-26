#ifndef COMBINATIONSUM_HPP
#define COMBINATIONSUM_HPP
#include <vector>
#include <algorithm>

using namespace std;

// Solution 1: Backtracking with sort + pruning. O(n^(t/m)) time, O(t/m) recursion depth.
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, target, 0, path, res);
        return res;
    }
private:
    void backtrack(vector<int>& c, int remaining, int start, vector<int>& path, vector<vector<int>>& res) {
        if (remaining == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < (int)c.size(); i++) { // O(n) branches
            if (c[i] > remaining) break; // prune: sorted
            path.push_back(c[i]);
            backtrack(c, remaining - c[i], i, path, res); // same i: allow reuse
            path.pop_back();
        }
    }
};

// Solution 2: Iterative DP. O(n*t*k) time, O(t*C) space.
class SolutionDP {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (int c : candidates) { // O(n)
            for (int s = c; s <= target; s++) { // O(t)
                for (auto& combo : dp[s - c]) {
                    dp[s].push_back(combo);
                    dp[s].back().push_back(c);
                }
            }
        }
        return dp[target];
    }
};

#endif
