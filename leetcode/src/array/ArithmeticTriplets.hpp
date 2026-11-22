#pragma once
#include <unordered_set>
#include <vector>
using namespace std;

// LeetCode 2367. Expected O(n) time and O(n) extra space.
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> values(nums.begin(), nums.end());
        int count = 0;
        for (int x : nums) {
            if (values.contains(x + diff) && values.contains(x + 2 * diff)) {
                ++count;
            }
        }
        return count;
    }
};
