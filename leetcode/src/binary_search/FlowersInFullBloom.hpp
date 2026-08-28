#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// LeetCode 2251: Number of Flowers in Full Bloom
class Solution {
public:
    // Solution 1: Binary Search
    // Sort starts and ends separately. For each person at time t,
    // flowers in bloom = (flowers started by t) - (flowers ended before t).
    // O((n+q) log n) time, O(n) space.
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> starts(n), ends(n);

        // O(n) extract start/end arrays
        for (int i = 0; i < n; i++) {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }

        // O(n log n) sort both arrays
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int q = people.size();
        vector<int> result(q);

        // O(q log n) binary search for each person
        for (int i = 0; i < q; i++) {
            int t = people[i];
            // Number of flowers that have started blooming by time t
            int started = upper_bound(starts.begin(), starts.end(), t) - starts.begin();
            // Number of flowers that have finished blooming before time t
            int ended = lower_bound(ends.begin(), ends.end(), t) - ends.begin();
            result[i] = started - ended;
        }
        return result;
    }
};

// Solution 2: Sweep Line
class SolutionSweepLine {
public:
    // Create events at bloom start (+1) and bloom end+1 (-1), sort events.
    // Sort queries by time, sweep through together.
    // O((n+q) log(n+q)) time, O(n+q) space.
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int q = people.size();

        // O(n) build event list: +1 at start, -1 at end+1
        vector<pair<int, int>> events;
        events.reserve(2 * n);
        for (auto& f : flowers) {
            events.push_back({f[0], 1});
            events.push_back({f[1] + 1, -1});
        }

        // O(n log n) sort events by time (ties broken by value so -1 before +1 at same time)
        sort(events.begin(), events.end());

        // O(q) build index-sorted queries
        vector<int> idx(q);
        iota(idx.begin(), idx.end(), 0);
        // O(q log q) sort query indices by arrival time
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return people[a] < people[b];
        });

        vector<int> result(q);
        int blooming = 0;
        int ei = 0;

        // O(n + q) sweep: process events up to each query time
        for (int i : idx) {
            int t = people[i];
            while (ei < (int)events.size() && events[ei].first <= t) {
                blooming += events[ei].second;
                ei++;
            }
            result[i] = blooming;
        }
        return result;
    }
};
