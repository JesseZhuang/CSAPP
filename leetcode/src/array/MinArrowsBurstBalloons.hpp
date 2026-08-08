#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Sort by end coordinate, greedily shoot at each group's rightmost reachable point.
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        // O(n log n) sort by end
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int arrows = 1;
        int arrowPos = points[0][1];
        // O(n) single pass
        for (int i = 1; i < (int)points.size(); ++i) {
            if (points[i][0] > arrowPos) {
                ++arrows;
                arrowPos = points[i][1];
            }
        }
        return arrows;
    }

    // Sort by start coordinate, track the shrinking overlap region.
    int findMinArrowShots2(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        // O(n log n) sort by start
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int arrows = 1;
        int overlapEnd = points[0][1];
        // O(n) single pass
        for (int i = 1; i < (int)points.size(); ++i) {
            if (points[i][0] <= overlapEnd) {
                // Shrink overlap to the common region
                overlapEnd = min(overlapEnd, points[i][1]);
            } else {
                ++arrows;
                overlapEnd = points[i][1];
            }
        }
        return arrows;
    }
};
