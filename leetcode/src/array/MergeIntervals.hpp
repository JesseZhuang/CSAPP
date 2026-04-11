#ifndef LEETCODE_MERGEINTERVALS_HPP
#define LEETCODE_MERGEINTERVALS_HPP

#include <algorithm>
#include <vector>

using namespace std;

// Time: O(n log n) — dominated by sorting
// Space: O(n) — for the result vector
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto &iv : intervals) {
            if (!res.empty() && iv[0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], iv[1]);
            } else {
                res.push_back(iv);
            }
        }
        return res;
    }
};

#endif //LEETCODE_MERGEINTERVALS_HPP
