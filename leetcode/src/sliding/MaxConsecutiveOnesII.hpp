#pragma once
#include <vector>

using namespace std;

// leet 487, sliding window. O(n) time, O(1) space.
class SolutionMaxConsecutiveOnesII {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int l = 0, r = 0, k = 1, n = nums.size();
        while (r < n) {
            if (nums[r++] == 0) --k;
            if (k < 0 && nums[l++] == 0) ++k;
        }
        return r - l;
    }
};
