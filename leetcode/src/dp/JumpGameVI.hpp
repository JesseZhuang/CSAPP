#pragma once

#include <deque>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class JumpGameVI {
public:
    // O(n) time: each index enters and leaves the deque once; O(n) space for DP.
    int maxResult(const vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        deque<int> candidates;
        dp[0] = nums[0];
        candidates.push_back(0);

        for (int index = 1; index < (int)nums.size(); ++index) {
            while (candidates.front() < index - k) candidates.pop_front();
            dp[index] = nums[index] + dp[candidates.front()];
            while (!candidates.empty() && dp[candidates.back()] <= dp[index]) {
                candidates.pop_back();
            }
            candidates.push_back(index);
        }

        return dp.back();
    }

    // O(n log n) time for heap operations, O(n) space with lazy expiry.
    int maxResultHeap(const vector<int>& nums, int k) {
        priority_queue<pair<int, int>> candidates;
        candidates.emplace(nums[0], 0);
        int score = nums[0];

        for (int index = 1; index < (int)nums.size(); ++index) {
            while (candidates.top().second < index - k) candidates.pop();
            score = nums[index] + candidates.top().first;
            candidates.emplace(score, index);
        }

        return score;
    }
};
