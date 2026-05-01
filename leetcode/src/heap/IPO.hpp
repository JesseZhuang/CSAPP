#pragma once
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// leet 502, greedy + max-heap. O(n log n + k log n) time, O(n) space.
class SolutionIPO {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());
        priority_queue<int> pq; // max-heap of profits
        int i = 0;
        while (k-- > 0) {
            while (i < n && projects[i].first <= w) pq.push(projects[i++].second);
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
