#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class CarPooling {
public:
    // Difference array approach
    // Time O(n + 1001), Space O(1001)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {};
        for (auto& t : trips) { // O(n)
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }
        int cur = 0;
        for (int i = 0; i <= 1000; ++i) { // O(1001)
            cur += diff[i];
            if (cur > capacity) return false;
        }
        return true;
    }

    // Sorted events sweep
    // Time O(n log n), Space O(n)
    bool carPooling2(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> events;
        for (auto& t : trips) { // O(n)
            events.emplace_back(t[1], t[0]);   // pick up
            events.emplace_back(t[2], -t[0]);  // drop off
        }
        sort(events.begin(), events.end()); // O(n log n)
        int cur = 0;
        for (auto& [loc, delta] : events) { // O(n)
            cur += delta;
            if (cur > capacity) return false;
        }
        return true;
    }
};
