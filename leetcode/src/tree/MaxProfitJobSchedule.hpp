#ifndef MAXPROFITJOBSCHEDULE_HPP
#define MAXPROFITJOBSCHEDULE_HPP

#include <algorithm>
#include <map>
#include <vector>
#include <__algorithm/ranges_sort.h>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        size_t n = startTime.size();
        vector<tuple<int, int, int> > info(n);
        for (size_t i = 0; i < n; i++) info.emplace_back(endTime[i], startTime[i], profit[i]);
        ranges::sort(info); // sort by end time first
        map<int, int> endProf{{0, 0}};
        for (auto [e,s,p]: info) {
            auto np = prev(endProf.upper_bound(s))->second + p; // upper_bound: first item greater
            if (np > endProf.rbegin()->second) endProf[e] = np;;
        }
        return endProf.rbegin()->second;
    }
};


#endif //MAXPROFITJOBSCHEDULE_HPP
