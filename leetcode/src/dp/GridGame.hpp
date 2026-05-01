#ifndef LEETCODE_GRIDGAME_HPP
#define LEETCODE_GRIDGAME_HPP

#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

// leet 2017
class Solution2017 {
public:
    long long gridGame(vector<vector<int>> &grid) {
        int n = grid[0].size();
        long long first = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long second = 0, res = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            first -= grid[0][i];
            res = min(res, max(first, second));
            second += grid[1][i];
        }
        return res;
    }
};

#endif //LEETCODE_GRIDGAME_HPP
