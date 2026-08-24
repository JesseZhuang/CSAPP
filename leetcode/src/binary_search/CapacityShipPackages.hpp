#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    // Binary Search on Answer + Greedy feasibility check.
    // O(n * log(sum-max)) time, O(1) space.
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canShip(weights, days, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    // Greedy check: can we ship all packages within `days` using capacity `cap`?
    bool canShip(vector<int>& weights, int days, int cap) {
        int needed = 1;
        int cur = 0;
        for (int w : weights) {
            if (cur + w > cap) {
                needed++;
                cur = 0;
                if (needed > days) return false;
            }
            cur += w;
        }
        return needed <= days;
    }
};
