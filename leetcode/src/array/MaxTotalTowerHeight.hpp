#ifndef LEETCODE_MAXTOTALTOWERHEIGHT_HPP
#define LEETCODE_MAXTOTALTOWERHEIGHT_HPP

#include <vector>
#include <algorithm>
#include "util/cph.hpp"

// LeetCode 3301
class Solution {
public:
    long long maximumTotalSum(vector<int> &maxH) {
        sort(rall(maxH));
        ll res = 0;
        int last = 1001001001; // > 10^9 constraint
        for (int h: maxH) {
            last = min(h, last - 1);
            if (last <= 0) return -1;
            res += last;
        }
        return res;
    }
};

#endif //LEETCODE_MAXTOTALTOWERHEIGHT_HPP
