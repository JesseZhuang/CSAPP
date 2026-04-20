#ifndef SUMOFSUBARRAYMINIMUMS_HPP
#define SUMOFSUBARRAYMINIMUMS_HPP

#include <stack>
#include <vector>

using namespace std;

/// LeetCode 907, medium, tags: array, dynamic programming, stack, monotonic stack.
class Solution907 {
public:
    static constexpr int MOD = 1'000'000'007;

    /// Monotonic stack with sentinels. O(n) time, O(n) space.
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        long long result = 0;
        stack<int> stk; // indices with increasing values
        stk.push(-1);   // sentinel

        for (int i = 0; i <= n; i++) { // O(n), each index pushed/popped once
            int curVal = (i == n) ? 0 : arr[i];
            while (stk.top() != -1 && arr[stk.top()] > curVal) {
                int mid = stk.top();
                stk.pop();
                long long left = mid - stk.top();  // distance to previous <= element
                long long right = i - mid;         // distance to next < element
                result = (result + (long long) arr[mid] * left * right) % MOD;
            }
            stk.push(i);
        }
        return (int) result;
    }
};

#endif //SUMOFSUBARRAYMINIMUMS_HPP
