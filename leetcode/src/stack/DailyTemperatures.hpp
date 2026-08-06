#pragma once
#include <stack>
#include <vector>

using namespace std;

namespace DailyTemperatures {

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0); // O(n) space
        stack<int> st; // monotonic decreasing stack of indices, O(n) space
        for (int i = 0; i < n; i++) { // O(n)
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) { // O(n) total pops
                int j = st.top();
                st.pop();
                res[j] = i - j;
            }
            st.push(i);
        }
        return res; // Time O(n), Space O(n)
    }
};

} // namespace DailyTemperatures
