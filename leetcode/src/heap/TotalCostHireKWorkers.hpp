#pragma once
#include <vector>
#include <queue>

using namespace std;

// leet 2462, two min-heaps for front/back candidates. O((k + n) log candidates) time, O(candidates) space.
class SolutionTotalCostHireKWorkers {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        // two min-heaps: store (cost, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> left, right;
        int lo = 0, hi = n - 1;
        // seed left heap
        while (lo < candidates && lo <= hi) left.push({costs[lo], lo}), lo++;
        // seed right heap
        while (hi >= lo && (n - 1 - hi) < candidates) right.push({costs[hi], hi}), hi--;

        long long total = 0;
        for (int i = 0; i < k; i++) {
            int lv = left.empty() ? INT_MAX : left.top().first;
            int rv = right.empty() ? INT_MAX : right.top().first;
            if (lv <= rv) {
                total += lv;
                left.pop();
                if (lo <= hi) { left.push({costs[lo], lo}); lo++; }
            } else {
                total += rv;
                right.pop();
                if (lo <= hi) { right.push({costs[hi], hi}); hi--; }
            }
        }
        return total;
    }
};

// Approach 2: single priority_queue with side tracking.
class SolutionTotalCostHireKWorkers2 {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        // (cost, index) min-heap; track which side each element came from via index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int lo = 0, hi = n - 1;
        // seed from both sides
        for (int i = 0; i < candidates && lo <= hi; i++, lo++) pq.push({costs[lo], lo});
        for (int i = 0; i < candidates && lo <= hi; i++, hi--) pq.push({costs[hi], hi});

        long long total = 0;
        for (int i = 0; i < k; i++) {
            auto [cost, idx] = pq.top(); pq.pop();
            total += cost;
            // determine which side this came from by index relative to current boundaries
            if (idx < lo) {
                // came from left side, replenish from left
                if (lo <= hi) { pq.push({costs[lo], lo}); lo++; }
            } else {
                // came from right side, replenish from right
                if (lo <= hi) { pq.push({costs[hi], hi}); hi--; }
            }
        }
        return total;
    }
};
