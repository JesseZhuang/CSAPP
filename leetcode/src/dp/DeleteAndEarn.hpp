#ifndef DELETEANDEARN_HPP
#define DELETEANDEARN_HPP
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// Solution 1: DP on frequency array (House Robber style).
// O(n + max_val) time, O(max_val) space.
class DeleteAndEarn {
public:
    int deleteAndEarn(vector<int> &nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> earn(maxVal + 1, 0);
        for (int x : nums) // O(n) — build earn array
            earn[x] += x;
        // House robber on earn[0..maxVal]
        int prev2 = 0, prev1 = 0;
        for (int v = 1; v <= maxVal; v++) { // O(max_val) time, O(1) extra space
            int cur = max(prev1, prev2 + earn[v]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

// Solution 2: Sort unique values + group DP.
// O(n + k log k) time, O(k) space where k = distinct values.
class DeleteAndEarnSort {
public:
    int deleteAndEarn(vector<int> &nums) {
        unordered_map<int, int> freq;
        for (int x : nums) // O(n)
            freq[x] += x;
        vector<int> keys;
        keys.reserve(freq.size());
        for (auto &[k, _] : freq)
            keys.push_back(k);
        sort(keys.begin(), keys.end()); // O(k log k)
        int prev2 = 0, prev1 = 0;
        for (int i = 0; i < (int)keys.size(); i++) { // O(k) — house robber on sorted unique keys
            int cur;
            if (i > 0 && keys[i] == keys[i - 1] + 1)
                cur = max(prev1, prev2 + freq[keys[i]]);
            else
                cur = prev1 + freq[keys[i]];
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

#endif //DELETEANDEARN_HPP
