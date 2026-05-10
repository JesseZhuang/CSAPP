#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Solution 1: Greedy - track last occurrence, expand partition end
// Time: O(n), Space: O(1)
class SolutionPartitionLabels {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {};
        for (int i = 0; i < (int)s.size(); i++)
            last[s[i] - 'a'] = i; // O(n) pass to record last occurrence

        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            end = max(end, last[s[i] - 'a']); // O(1) expand partition end
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};

// Solution 2: Merge Intervals - build [first, last] per char, sort and merge
// Time: O(n), Space: O(1) (at most 26 intervals)
class SolutionPartitionLabels2 {
public:
    vector<int> partitionLabels(string s) {
        int first[26], last[26];
        fill(first, first + 26, -1);
        fill(last, last + 26, -1);

        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        // Collect intervals for chars that appear
        vector<pair<int,int>> intervals;
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1)
                intervals.push_back({first[i], last[i]});
        }

        // Sort by start position
        sort(intervals.begin(), intervals.end());

        // Merge overlapping intervals
        vector<int> res;
        int start = intervals[0].first, end = intervals[0].second;
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i].first <= end) {
                end = max(end, intervals[i].second); // merge
            } else {
                res.push_back(end - start + 1);
                start = intervals[i].first;
                end = intervals[i].second;
            }
        }
        res.push_back(end - start + 1); // last partition
        return res;
    }
};
