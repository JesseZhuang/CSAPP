#ifndef K_RADIUS_SUBARRAY_AVERAGES_HPP
#define K_RADIUS_SUBARRAY_AVERAGES_HPP

#include <vector>
using namespace std;

// LeetCode 2090. Rolling window: O(n) time, O(1) extra space excluding output.
class KRadiusSubarrayAverages {
public:
    static vector<int> getAverages(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        vector<int> averages(n, -1);
        const long long window = 2LL * k + 1;
        if (window > n) return averages;

        long long sum = 0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            if (right >= window) sum -= nums[right - window];
            if (right >= window - 1) {
                // Signed integer division truncates negative averages toward zero.
                averages[right - k] = static_cast<int>(sum / window);
            }
        }
        return averages;
    }

    // Prefix sums: O(n) time and O(n) extra space excluding output.
    static vector<int> getAveragesByPrefixSum(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        vector<int> averages(n, -1);
        const long long window = 2LL * k + 1;
        if (window > n) return averages;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for (int center = k; center < n - k; ++center) {
            const long long sum = prefix[center + k + 1] - prefix[center - k];
            averages[center] = static_cast<int>(sum / window);
        }
        return averages;
    }
};

#endif
