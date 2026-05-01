#ifndef LEETCODE_POWERKSIZESUBARRAYSI_HPP
#define LEETCODE_POWERKSIZESUBARRAYSI_HPP

#include <vector>

using namespace std;

class PowerKSizeSubArraysI {
public:
    // O(n) time, O(1) space.
    vector<int> resultsArray(vector<int> &nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        int streak = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) streak++;
            else streak = 1;
            if (streak >= k) res[i - k + 2] = nums[i + 1];
        }
        return res;
    }
};

#endif //LEETCODE_POWERKSIZESUBARRAYSI_HPP
