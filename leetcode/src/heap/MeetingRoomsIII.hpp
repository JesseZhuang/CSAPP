#ifndef LEETCODE_MEETINGROOMSIII_HPP
#define LEETCODE_MEETINGROOMSIII_HPP

#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        vector<int> rooms(n);
        iota(rooms.begin(), rooms.end(), 0);
        priority_queue<int, vector<int>, greater<>> free{rooms.begin(), rooms.end()};
        typedef pair<long, int> ri;
        priority_queue<ri, vector<ri>, greater<>> used;
        vector<int> cnt(n, 0);
        sort(meetings.begin(), meetings.end());
        for (auto &m: meetings) {
            int s = m[0], e = m[1];
            while (!used.empty() && used.top().first <= s) {
                free.push(used.top().second);
                used.pop();
            }
            int room;
            if (!free.empty()) {
                room = free.top();
                free.pop();
                used.emplace((long) e, room);
            } else {
                auto fm = used.top();
                room = fm.second;
                used.pop();
                used.emplace(fm.first + e - s, room);
            }
            cnt[room]++;
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};

#endif //LEETCODE_MEETINGROOMSIII_HPP
