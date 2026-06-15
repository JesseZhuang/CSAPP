#ifndef LEETCODE_INSERTINTERVAL_HPP
#define LEETCODE_INSERTINTERVAL_HPP

#include <vector>

using namespace std;

// LeetCode 57 - Insert Interval
// Time: O(n) — single pass
// Space: O(n) — for the result vector
class InsertIntervalSolution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

#endif //LEETCODE_INSERTINTERVAL_HPP
