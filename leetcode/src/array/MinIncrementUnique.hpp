#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class MinIncrementUnique {
public:
    // Sort + Greedy
    // Time O(n log n), Space O(1) ignoring sort space
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(n log n)
        int moves = 0;
        for (int i = 1; i < (int)nums.size(); ++i) { // O(n)
            if (nums[i] <= nums[i - 1]) {
                int target = nums[i - 1] + 1;
                moves += target - nums[i]; // accumulate cost
                nums[i] = target;          // push current to prev+1
            }
        }
        return moves;
    }

    // Counting Sort / Frequency Sweep
    // Time O(n + max_val), Space O(max_val)
    int minIncrementForUnique2(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int MAXV = 200001; // nums[i] <= 1e5, but duplicates can push up to ~2e5
        vector<int> cnt(MAXV, 0);
        for (int x : nums) cnt[x]++; // O(n) — count frequencies
        int moves = 0;
        for (int i = 0; i < MAXV - 1; ++i) { // O(max_val) — sweep forward
            if (cnt[i] > 1) {
                int extra = cnt[i] - 1; // extras that must move
                cnt[i + 1] += extra;    // push extras to next slot
                moves += extra;         // each extra costs 1 increment
                cnt[i] = 1;
            }
        }
        return moves;
    }
};
