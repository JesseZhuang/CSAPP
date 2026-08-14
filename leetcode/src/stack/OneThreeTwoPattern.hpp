#pragma once
#include <climits>
#include <stack>
#include <vector>

using namespace std;

namespace OneThreeTwoPattern {

class Solution {
public:
    // Monotonic stack scanning right to left, tracking largest popped value as '2' candidate.
    // Time O(n), Space O(n)
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        stack<int> st; // monotonic decreasing stack (candidates for '3')
        int second = INT_MIN; // largest popped value (candidate for '2')
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < second) return true; // nums[i] is '1'
            while (!st.empty() && nums[i] > st.top()) {
                second = st.top(); // update '2' candidate
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }

    // Prefix min + monotonic stack.
    // Time O(n), Space O(n)
    bool find132patternPrefixMin(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> prefixMin(n);
        prefixMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prefixMin[i - 1], nums[i]);
        }
        stack<int> st; // monotonic decreasing stack (candidates for '2')
        for (int j = n - 1; j >= 0; j--) {
            // nums[j] is candidate for '3', prefixMin[j] is '1'
            if (nums[j] > prefixMin[j]) {
                while (!st.empty() && st.top() <= prefixMin[j]) {
                    st.pop();
                }
                if (!st.empty() && st.top() < nums[j]) return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};

} // namespace OneThreeTwoPattern
