#ifndef LEETCODE_LARGESTRECTANGLEHISTOGRAM_HPP
#define LEETCODE_LARGESTRECTANGLEHISTOGRAM_HPP

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution84 {
public:
    int largestRectangleAreaStack(vector<int> &heights) {
        int n = static_cast<int>(heights.size());
        stack<int> st; // monotonic increasing stack of indices
        int maxArea = 0;
        for (int i = 0; i <= n; i++) { // O(n)
            int h = i == n ? 0 : heights[i];
            while (!st.empty() && h < heights[st.top()]) { // each index pushed/popped once, O(n) total
                int curHeight = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, curHeight * width);
            }
            st.push(i);
        }
        return maxArea; // Time O(n), Space O(n)
    }

    int largestRectangleAreaArray(vector<int> &heights) {
        int n = static_cast<int>(heights.size());
        vector<int> leftWall(n, -1), rightWall(n, n);
        for (int i = 1; i < n; i++) { // O(n) amortized
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) p = leftWall[p];
            leftWall[i] = p;
        }
        for (int i = n - 2; i >= 0; i--) { // O(n) amortized
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) p = rightWall[p];
            rightWall[i] = p;
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) // O(n)
            maxArea = max(maxArea, heights[i] * (rightWall[i] - leftWall[i] - 1));
        return maxArea; // Time O(n), Space O(n)
    }
};

#endif //LEETCODE_LARGESTRECTANGLEHISTOGRAM_HPP
