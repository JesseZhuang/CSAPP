#ifndef LEETCODE_TRAPPINGRAINWATER_HPP
#define LEETCODE_TRAPPINGRAINWATER_HPP

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// Solution 1: Two Pointers - Time O(n), Space O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int left = 0, right = n - 1;       // O(1) two boundary pointers
        int leftMax = 0, rightMax = 0;      // O(1) track max from each side
        int water = 0;

        while (left < right) {              // O(n) single pass from both ends
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left]; // update left max boundary
                else
                    water += leftMax - height[left]; // trapped = leftMax - current
                ++left;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right]; // update right max boundary
                else
                    water += rightMax - height[right]; // trapped = rightMax - current
                --right;
            }
        }
        return water;
    }
};

// Solution 2: Monotonic Stack - Time O(n), Space O(n)
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        stack<int> stk;                     // O(n) stack of indices, decreasing height
        int water = 0;

        for (int i = 0; i < n; ++i) {      // O(n) each index pushed/popped at most once
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int bottom = stk.top();     // valley bottom index
                stk.pop();
                if (stk.empty()) break;     // no left wall, water spills

                int left = stk.top();
                int width = i - left - 1;                           // horizontal span
                int bounded = min(height[left], height[i]) - height[bottom]; // vertical depth
                water += width * bounded;   // rectangular area of trapped water
            }
            stk.push(i);
        }
        return water;
    }
};

#endif // LEETCODE_TRAPPINGRAINWATER_HPP
