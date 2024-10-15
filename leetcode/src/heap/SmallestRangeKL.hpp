#ifndef LEETCODE_SMALLESTRANGEKL_HPP
#define LEETCODE_SMALLESTRANGEKL_HPP

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        typedef tuple<int, int, int> t3;
        priority_queue<t3, vector<t3>, greater<>> pq;
        int maxV = INT_MIN, left = -1e5, right = 1e5;
        for (int r = 0; r < nums.size(); r++) {
            int v = nums[r][0];
            pq.emplace(v, r, 0);
            maxV = max(maxV, v);
        }
        while (!pq.empty()) {
            auto [v, r, c] = pq.top();
            pq.pop();
            if (maxV - v < right - left)
                left = v, right = maxV;
            if (c == nums[r].size() - 1) break;
            c += 1;
            pq.emplace(nums[r][c], r, c);
            maxV = max(nums[r][c], maxV);
        }
        return {left, right};
    }
};


#endif //LEETCODE_SMALLESTRANGEKL_HPP
