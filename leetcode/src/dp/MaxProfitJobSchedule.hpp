#ifndef MAXPROFITJOBSCHEDULE_HPP
#define MAXPROFITJOBSCHEDULE_HPP

#include <algorithm>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

// leetcode 1235
class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        const size_t n = startTime.size();
        vector<tuple<int, int, int>> jobs(n);
        for (size_t i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        ranges::sort(jobs, {}, [](const auto &t) { return get<1>(t); });
        map<int, int> endProf{{0, 0}};
        for (const auto &[s, e, p] : jobs) {
            auto it = endProf.upper_bound(s);
            int np = prev(it)->second + p;
            if (np > endProf.rbegin()->second)
                endProf[e] = np;
        }
        return endProf.rbegin()->second;
    }
};

class Solution2 {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        const int n = static_cast<int>(startTime.size());
        vector<tuple<int, int, int>> jobs(n);
        for (int i = 0; i < n; i++)
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        ranges::sort(jobs);
        vector<int> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = get<0>(jobs[i]);
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int s = get<1>(jobs[i - 1]);
            int p = get<2>(jobs[i - 1]);
            int j = static_cast<int>(upper_bound(ends.begin(), ends.begin() + (i - 1), s) - ends.begin());
            dp[i] = max(dp[i - 1], dp[j] + p);
        }
        return dp[n];
    }
};

#endif // MAXPROFITJOBSCHEDULE_HPP
