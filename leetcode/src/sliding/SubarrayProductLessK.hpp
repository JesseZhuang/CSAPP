#pragma once
#include <vector>
#include <cmath>
using namespace std;

// leet 713, sliding window, O(n) time, O(1) space
class SolutionSubarrayProductLessK {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1;
        for (int l = 0, r = 0; r < (int)nums.size(); r++) {
            prod *= nums[r];
            while (prod >= k) prod /= nums[l++];
            res += r - l + 1;
        }
        return res;
    }
};

// leet 713, log prefix sum + binary search, O(n log n) time, O(n) space
class SolutionSubarrayProductLessK2 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        double logK = log(k);
        int n = nums.size();
        vector<double> lps(n + 1, 0);
        for (int i = 0; i < n; i++) lps[i + 1] = lps[i] + log(nums[i]);
        int res = 0;
        for (int cur = 0; cur < n; cur++) {
            int low = cur + 1, high = n + 1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (lps[mid] - lps[cur] < logK - 1e-9) low = mid + 1;
                else high = mid;
            }
            res += low - cur - 1;
        }
        return res;
    }
};
