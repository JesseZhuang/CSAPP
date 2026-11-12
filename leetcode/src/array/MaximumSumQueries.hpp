#ifndef LEETCODE_MAXIMUMSUMQUERIES_HPP
#define LEETCODE_MAXIMUMSUMQUERIES_HPP

#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2,
                                 vector<vector<int>> &queries) {
        const int n = static_cast<int>(nums1.size());
        vector<pair<int, int>> points;
        points.reserve(n);
        for (int i = 0; i < n; ++i) {
            points.emplace_back(nums1[i], nums2[i]);
        }
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });

        vector<int> coordinates = nums2;
        sort(coordinates.begin(), coordinates.end());
        coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
        const int m = static_cast<int>(coordinates.size());

        vector<int> order(queries.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a][0] > queries[b][0];
        });

        // Reversed compressed coordinates turn b >= y into a prefix maximum.
        vector<int> fenwick(m + 1, -1);
        vector<int> result(queries.size(), -1);
        int next = 0;
        for (int qi : order) {
            const int x = queries[qi][0], y = queries[qi][1];
            while (next < n && points[next].first >= x) {
                const auto [a, b] = points[next++];
                const int rank = static_cast<int>(lower_bound(coordinates.begin(), coordinates.end(), b)
                                                  - coordinates.begin());
                for (int i = m - rank; i <= m; i += i & -i) {
                    fenwick[i] = max(fenwick[i], a + b);
                }
            }
            const int rank = static_cast<int>(lower_bound(coordinates.begin(), coordinates.end(), y)
                                              - coordinates.begin());
            for (int i = m - rank; i > 0; i -= i & -i) {
                result[qi] = max(result[qi], fenwick[i]);
            }
        }
        // Time: O(n log n + q log q + (n + q) log n), including query sorting.
        // Auxiliary space: O(n + q). Valid sums fit in int (at most 2,000,000,000).
        return result;
    }
};

#endif //LEETCODE_MAXIMUMSUMQUERIES_HPP
