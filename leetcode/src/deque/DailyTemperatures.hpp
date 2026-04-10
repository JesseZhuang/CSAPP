#ifndef LEETCODE_DAILYTEMPERATURES_HPP
#define LEETCODE_DAILYTEMPERATURES_HPP

#include <vector>
#include <stack>

using namespace std;

class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = static_cast<int>(temperatures.size());
        vector<int> res(n, 0);
        stack<int> st; // monotonic decreasing stack of indices
        for (int i = 0; i < n; i++) { // O(n)
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) { // O(n) total
                int j = st.top();
                st.pop();
                res[j] = i - j;
            }
            st.push(i);
        }
        return res; // Time O(n), Space O(n)
    }
};

#endif //LEETCODE_DAILYTEMPERATURES_HPP
