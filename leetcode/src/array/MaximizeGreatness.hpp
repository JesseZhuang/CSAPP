#ifndef LEETCODE_MAXIMIZEGREATNESS_HPP
#define LEETCODE_MAXIMIZEGREATNESS_HPP

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximizeGreatness(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        // Runtime is O(n log n); sorting uses O(log n) stack space and the scan O(1).
        int matched = 0;
        for (int candidate = 0; candidate < nums.size(); ++candidate) {
            if (nums[candidate] > nums[matched]) {
                ++matched;
            }
        }
        return matched;
    }
};

#endif // LEETCODE_MAXIMIZEGREATNESS_HPP
