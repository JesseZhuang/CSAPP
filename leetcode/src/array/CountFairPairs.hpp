#ifndef LEETCODE_COUNTFAIRPAIRS_HPP
#define LEETCODE_COUNTFAIRPAIRS_HPP

#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        long long res = 0;
        auto beg = nums.begin(), end = nums.end();
        sort(beg, end);
        for (auto [i, v]: views::enumerate(nums)) // since C++23
            res += upper_bound(beg + i + 1, end, upper - v)
                   - lower_bound(beg + i + 1, end, lower - v);
        return res;
    }
};

#endif //LEETCODE_COUNTFAIRPAIRS_HPP
