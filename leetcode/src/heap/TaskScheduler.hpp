#pragma once

#include <vector>
#include <algorithm>

using namespace std;

// lc 621 - Task Scheduler
// Math/greedy: O(n) time, O(1) space.
class Solution621 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {};
        int maxFreq = 0, maxCnt = 0;
        for (char t : tasks) { // O(n)
            count[t - 'A']++;
            if (count[t - 'A'] > maxFreq) {
                maxFreq = count[t - 'A'];
                maxCnt = 1;
            } else if (count[t - 'A'] == maxFreq) {
                maxCnt++;
            }
        }
        int nGaps = maxFreq - 1;
        int gapLen = n + 1;
        return max((int)tasks.size(), nGaps * gapLen + maxCnt);
    }
};
