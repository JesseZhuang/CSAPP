#ifndef LEETCODE_FREQMOSTFREQUENTELEMENT_HPP
#define LEETCODE_FREQMOSTFREQUENTELEMENT_HPP

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// leet 1838, sliding window. O(n log n) time, O(1) space.
class SolutionFreqMostFrequentSW {
public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int left = 0, res = 1;
        long long windowSum = 0;
        for (int right = 0; right < n; right++) {
            windowSum += nums[right];
            // cost to make all elements in [left, right] equal to nums[right]
            while ((long long) nums[right] * (right - left + 1) - windowSum > k) {
                windowSum -= nums[left];
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

// leet 1838, binary search + prefix sum. O(n log n) time, O(n) space.
class SolutionFreqMostFrequentBS {
public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        int res = 1;
        for (int right = 0; right < n; right++) {
            // binary search for the smallest left such that
            // nums[right] * (right - left + 1) - (prefix[right+1] - prefix[left]) <= k
            int lo = 0, hi = right;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                long long cost = (long long) nums[right] * (right - mid + 1) - (prefix[right + 1] - prefix[mid]);
                if (cost <= k) hi = mid;
                else lo = mid + 1;
            }
            long long cost = (long long) nums[right] * (right - lo + 1) - (prefix[right + 1] - prefix[lo]);
            if (cost <= k) res = max(res, right - lo + 1);
        }
        return res;
    }
};

#endif //LEETCODE_FREQMOSTFREQUENTELEMENT_HPP
