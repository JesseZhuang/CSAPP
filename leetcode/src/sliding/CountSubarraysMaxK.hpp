#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// leet 2962, sliding window, O(n) time, O(1) space
class SolutionCountSubarraysMaxK {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end()); // O(n) find max
        long long res = 0;
        int cnt = 0; // count of max element in window
        for (int l = 0, r = 0; r < (int)nums.size(); r++) {
            if (nums[r] == mx) cnt++;
            while (cnt >= k) { // shrink until fewer than k maxes
                if (nums[l] == mx) cnt--;
                l++;
            }
            res += l; // all starts in [0, l) form valid subarrays ending at r
        }
        return res;
    }
};

// leet 2962, binary search on max-element positions, O(n log n) time, O(n) space
class SolutionCountSubarraysMaxK2 {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> pos; // positions where max element occurs, O(n) space
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] == mx) pos.push_back(i);
        long long res = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            // binary search: find index j in pos where pos[j] <= r
            // if there are >= k such positions, earliest valid left = pos[j-k+1] + 1
            int hi = (int)(upper_bound(pos.begin(), pos.end(), r) - pos.begin()); // O(log n)
            if (hi >= k)
                res += pos[hi - k] + 1; // number of valid starting indices
        }
        return res;
    }
};
