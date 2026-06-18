#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class JumpGame {
public:
    // Greedy forward: track the maximum reachable index
    bool canJumpForward(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }

    // Greedy backward: find the smallest index that can reach the end
    bool canJumpBackward(vector<int>& nums) {
        int target = (int)nums.size() - 1;
        for (int i = target - 1; i >= 0; i--) {
            if (i + nums[i] >= target) {
                target = i;
            }
        }
        return target == 0;
    }
};
