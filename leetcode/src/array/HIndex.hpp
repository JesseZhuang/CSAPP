#pragma once
#include <algorithm>
#include <vector>
using namespace std;

class HIndex {
public:
    // O(n) time and O(n) space.
    int hIndex(vector<int>& citations) {
        int n = (int)citations.size();
        vector<int> counts(n + 1, 0);
        for (int citation : citations)
            ++counts[min(citation, n)];

        int papers = 0;
        for (int h = n; h >= 0; --h) {
            papers += counts[h];
            if (papers >= h)
                return h;
        }
        return 0;
    }

    // O(n log n) time and O(n) extra space for the sorted copy.
    int hIndexSort(vector<int>& citations) {
        vector<int> sorted = citations;
        sort(sorted.begin(), sorted.end());
        int n = (int)sorted.size();
        for (int i = 0; i < n; ++i) {
            int h = n - i;
            if (sorted[i] >= h)
                return h;
        }
        return 0;
    }
};
