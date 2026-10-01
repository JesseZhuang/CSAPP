#pragma once

#include <functional>
#include <queue>
#include <vector>

using namespace std;

// LeetCode 3066 - Minimum Operations to Exceed Threshold Value II.
// Min-heap simulation: O(n log n) time, O(n) space.
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
        }

        int operations = 0;
        while (minHeap.top() < k) {
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            minHeap.push(2 * x + y);
            ++operations;
        }
        return operations;
    }
};
