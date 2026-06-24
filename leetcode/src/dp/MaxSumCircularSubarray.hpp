#ifndef MAXSUMCIRCULARSUBARRAY_HPP
#define MAXSUMCIRCULARSUBARRAY_HPP
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int x : nums) {
            total += x;
            curMax = max(curMax + x, x);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + x, x);
            minSum = min(minSum, curMin);
        }

        // If all elements are negative, maxSum is the answer
        return maxSum < 0 ? maxSum : max(maxSum, total - minSum);
    }
};
#endif
