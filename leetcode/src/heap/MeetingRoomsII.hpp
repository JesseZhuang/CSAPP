#ifndef LEETCODE_MEETINGROOMSII_HPP
#define LEETCODE_MEETINGROOMSII_HPP

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// leet 253, min-heap approach. O(n log n) time, O(n) space.
class MeetingRoomsII {
public:
    int minMeetingRoomsHeap(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end()); // O(n log n)
        priority_queue<int, vector<int>, greater<>> pq; // min-heap of end times

        for (auto &iv: intervals) { // O(n)
            if (!pq.empty() && pq.top() <= iv[0]) pq.pop(); // O(log n)
            pq.push(iv[1]); // O(log n)
        }

        return (int) pq.size();
    }

    // sweep line: sort starts and ends separately. O(n log n) time, O(n) space.
    int minMeetingRoomsSweep(vector<vector<int>> &intervals) {
        int n = (int) intervals.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        sort(starts.begin(), starts.end()); // O(n log n)
        sort(ends.begin(), ends.end()); // O(n log n)

        int rooms = 0, endPtr = 0;
        for (int i = 0; i < n; i++) { // O(n)
            if (starts[i] < ends[endPtr]) rooms++;
            else endPtr++;
        }

        return rooms;
    }
};

#endif //LEETCODE_MEETINGROOMSII_HPP
