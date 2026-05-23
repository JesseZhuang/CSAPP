#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class NonOverlapIntervals {
public:
    // Sort by end, greedily keep non-overlapping intervals.
    // O(n log n) time, O(log n) space (sorting)
    static int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int count = 0;
        int end = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                ++count; // overlap, remove current
            } else {
                end = intervals[i][1];
            }
        }
        return count;
    }

    // Sort by start, on overlap keep interval with smaller end.
    // O(n log n) time, O(log n) space (sorting)
    static int eraseOverlapIntervals2(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int end = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                ++count;
                end = min(end, intervals[i][1]); // keep the one with smaller end
            } else {
                end = intervals[i][1];
            }
        }
        return count;
    }
};
