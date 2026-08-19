#pragma once
#include <vector>
#include <algorithm>

using namespace std;

// LeetCode 45, medium, tags: array, dp, greedy.
class JumpGameII {
public:
    // Greedy, O(n) time, O(1) space.
    int jump(vector<int>& nums) {
        int res = 0, reach = 0, p = 0;
        for (int i = 0; p < (int)nums.size() - 1; i++) {
            reach = max(reach, nums[i] + i);
            if (i == p) {
                res++;
                p = reach;
            }
        }
        return res;
    }

    // BFS level-order, O(n) time, O(1) space.
    int jumpBFS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int level = 0, curEnd = 0, nxtEnd = 0;
        for (int i = 0; i < n - 1; i++) {
            nxtEnd = max(nxtEnd, i + nums[i]);
            if (i == curEnd) {
                level++;
                curEnd = nxtEnd;
                if (curEnd >= n - 1) break;
            }
        }
        return level;
    }
};
