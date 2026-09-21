#ifndef LEETCODE_MINIMIZEMAXOFARRAY_HPP
#define LEETCODE_MINIMIZEMAXOFARRAY_HPP

#include <vector>
#include <algorithm>
using namespace std;

// Prefix sum greedy: answer = max(ceil(prefix_sum / (i+1))) for all i.
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefix = 0;
        long long ans = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            prefix += nums[i];
            // ceil(prefix / (i+1))
            long long candidate = (prefix + i) / (i + 1);
            ans = max(ans, candidate);
        }
        return (int)ans;
    }
};

// Binary search on answer, check feasibility by scanning left-to-right.
class Solution2 {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int lo = 0, hi = *max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(nums, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
private:
    bool feasible(vector<int>& nums, int cap) {
        // excess tracks how much overflow from right elements can be
        // pushed left. If excess goes negative, cap is too small.
        long long excess = 0;
        for (int x : nums) {
            excess += (long long)cap - x;
            if (excess < 0) return false;
        }
        return true;
    }
};

#endif // LEETCODE_MINIMIZEMAXOFARRAY_HPP
