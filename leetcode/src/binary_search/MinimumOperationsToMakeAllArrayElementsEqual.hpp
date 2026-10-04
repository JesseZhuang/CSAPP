#pragma once

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // Sort and prefix sums make each query O(log n), for O((n+m) log n) total time.
    // O(n) extra space for the prefix sums and result.
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        vector<long long> prefixSums(nums.size() + 1);
        for (size_t index = 0; index < nums.size(); ++index) {
            prefixSums[index + 1] = prefixSums[index] + nums[index];
        }

        vector<long long> result;
        result.reserve(queries.size());
        for (int query : queries) {
            const size_t splitIndex = lower_bound(nums.begin(), nums.end(), query) - nums.begin();
            const long long leftCost = static_cast<long long>(query) * splitIndex - prefixSums[splitIndex];
            const long long rightCost = (prefixSums.back() - prefixSums[splitIndex])
                - static_cast<long long>(query) * (nums.size() - splitIndex);
            result.push_back(leftCost + rightCost);
        }

        return result;
    }
};
