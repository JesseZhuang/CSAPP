#pragma once
#include <stack>
#include <vector>

using namespace std;

namespace NextGreaterElementII {

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // O(n) space
        stack<int> st; // monotonic decreasing stack of indices, O(n) space
        for (int i = 0; i < 2 * n; i++) { // O(n)
            while (!st.empty() && nums[st.top()] < nums[i % n]) { // O(n) total pops
                res[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) st.push(i);
        }
        return res; // Time O(n), Space O(n)
    }
};

} // namespace NextGreaterElementII
