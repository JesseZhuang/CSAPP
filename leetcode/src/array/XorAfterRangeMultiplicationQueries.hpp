#ifndef LEETCODE_XORAFTERRANGEMULTIPLICATIONQUERIES_HPP
#define LEETCODE_XORAFTERRANGEMULTIPLICATIONQUERIES_HPP

#include <vector>

using namespace std;

class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    int xorAfterRangeMultiplicationQueries(vector<int> &nums, vector<vector<int>> &queries) {
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k)
                nums[idx] = (long long)nums[idx] * v % MOD;
        }
        int res = 0;
        for (int x : nums)
            res ^= x;
        return res;
    }
};

#endif //LEETCODE_XORAFTERRANGEMULTIPLICATIONQUERIES_HPP
