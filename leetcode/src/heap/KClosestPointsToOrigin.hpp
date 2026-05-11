#ifndef LEETCODE_KCLOSESTPOINTSTOORIGIN_HPP
#define LEETCODE_KCLOSESTPOINTSTOORIGIN_HPP

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// leet 973, max-heap of size k. O(n log k) time, O(k) space.
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        // max-heap by squared distance
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto &p : points) { // O(n log k)
            pq.push(p);
            if ((int) pq.size() > k) pq.pop(); // evict farthest
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

// leet 973, nth_element / quickselect. O(n) average time, O(1) space.
class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(),
                    [](const vector<int> &a, const vector<int> &b) {
                        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
                    });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

#endif //LEETCODE_KCLOSESTPOINTSTOORIGIN_HPP
