#ifndef HOUSEROBBER_II_HPP
#define HOUSEROBBER_II_HPP
#include <algorithm>
#include <vector>

using namespace std;

// DP with two variables. O(N) time, O(1) space.
// Split circular into two linear sub-problems: [0, n-1) and [1, n).
class HouseRobberII {
    int robRange(vector<int> &nums, int lo, int hi) {
        int robPrev = 0, nRobPrev = 0;
        for (int i = lo; i < hi; i++) {
            int robCur = nRobPrev + nums[i];
            nRobPrev = max(nRobPrev, robPrev);
            robPrev = robCur;
        }
        return max(robPrev, nRobPrev);
    }
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robRange(nums, 0, n - 1), robRange(nums, 1, n));
    }
};

#endif //HOUSEROBBER_II_HPP
