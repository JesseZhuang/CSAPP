#pragma once

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Binary Search on Answer + Greedy consecutive count.
    // O(n * log(max_day)) time, O(1) extra space.
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // Impossible if we need more flowers than available
        if ((long long)m * k > n) return -1;

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        // Binary search on the number of days
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    // Greedy check: can we make at least m bouquets of k adjacent flowers by day?
    // O(n) time.
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int consecutive = 0;
        for (int b : bloomDay) {
            if (b <= day) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                    if (bouquets >= m) return true;  // early exit
                }
            } else {
                consecutive = 0;
            }
        }
        return bouquets >= m;
    }
};
