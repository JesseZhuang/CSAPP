#ifndef LEETCODE_PRODUCTEXCEPTSELF_HPP
#define LEETCODE_PRODUCTEXCEPTSELF_HPP

#include <vector>

using namespace std;

// leet 238, O(n) time, O(1) extra space
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; i++) { // O(n)
            res[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) { // O(n)
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};

// O(n) time, O(n) space
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1); // O(n) space each
        for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] * nums[i-1]; // O(n)
        for (int i = n-2; i >= 0; i--) suffix[i] = suffix[i+1] * nums[i+1]; // O(n)
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = prefix[i] * suffix[i]; // O(n)
        return res;
    }
};

#endif
