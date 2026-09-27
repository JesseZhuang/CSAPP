#ifndef ROTATEARRAY_HPP
#define ROTATEARRAY_HPP
#include <vector>
#include <algorithm>

using namespace std;

// Solution 1: Triple reverse. O(n) time, O(1) space.
class Solution189 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // handle k >= n
        reverse(nums.begin(), nums.end());           // O(n) reverse all
        reverse(nums.begin(), nums.begin() + k);     // O(k) reverse first k
        reverse(nums.begin() + k, nums.end());       // O(n-k) reverse last n-k
    }
};

// Solution 2: Extra array copy. O(n) time, O(n) space.
class Solution189ExtraArray {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tmp(n); // O(n) extra space
        for (int i = 0; i < n; i++) // O(n) copy to shifted positions
            tmp[(i + k) % n] = nums[i];
        nums = tmp;
    }
};

#endif
