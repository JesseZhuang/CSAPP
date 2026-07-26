#ifndef LEETCODE_FINDKPAIRSMALLESTSUMS_HPP
#define LEETCODE_FINDKPAIRSMALLESTSUMS_HPP

#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

// LeetCode 373: Find K Pairs with Smallest Sums
// Given two sorted arrays nums1, nums2 and integer k,
// return k pairs (u,v) with the smallest sums.
class SolutionFindKPairs {
public:
    // Solution 1: Min-heap approach.
    // Push first row (nums1[i], nums2[0]) for i in [0, min(k, n1)).
    // Pop smallest, advance column index j for that row.
    // Time O(k log k), Space O(k).
    static vector<vector<int>> kSmallestPairsHeap(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) return res;

        int n1 = nums1.size(), n2 = nums2.size();

        // min-heap: {sum, index_in_nums1, index_in_nums2}
        auto cmp = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
            return get<0>(a) > get<0>(b); // min-heap by sum
        };
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, decltype(cmp)> pq(cmp);

        // Seed heap with nums1[i] + nums2[0] for each row. O(min(k, n1) log k)
        for (int i = 0; i < min(k, n1); ++i) {
            pq.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !pq.empty()) { // O(k log k) total
            auto [sum, i, j] = pq.top();
            pq.pop();                     // O(log k) per pop
            res.push_back({nums1[i], nums2[j]});

            if (j + 1 < n2) {            // advance column for this row
                pq.emplace(nums1[i] + nums2[j + 1], i, j + 1); // O(log k) per push
            }
        }
        return res;
    }

    // Solution 2: BFS-like with visited set.
    // Start at (0,0), expand right (i, j+1) and down (i+1, j).
    // Use set<pair<int,int>> to avoid duplicate expansions.
    // Time O(k log k), Space O(k).
    static vector<vector<int>> kSmallestPairsBFS(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) return res;

        int n1 = nums1.size(), n2 = nums2.size();

        // min-heap: {sum, i, j}
        auto cmp = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
            return get<0>(a) > get<0>(b); // min-heap
        };
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, decltype(cmp)> pq(cmp);

        set<pair<int,int>> visited; // track visited (i,j) pairs. O(k) space

        pq.emplace(nums1[0] + nums2[0], 0, 0);
        visited.insert({0, 0});

        while (k-- > 0 && !pq.empty()) { // O(k) iterations
            auto [sum, i, j] = pq.top();
            pq.pop();                     // O(log k)
            res.push_back({nums1[i], nums2[j]});

            // Expand right: same row, next column
            if (j + 1 < n2 && visited.find({i, j + 1}) == visited.end()) {
                pq.emplace(nums1[i] + nums2[j + 1], i, j + 1); // O(log k)
                visited.insert({i, j + 1});                      // O(log k)
            }
            // Expand down: next row, same column
            if (i + 1 < n1 && visited.find({i + 1, j}) == visited.end()) {
                pq.emplace(nums1[i + 1] + nums2[j], i + 1, j); // O(log k)
                visited.insert({i + 1, j});                      // O(log k)
            }
        }
        return res;
    }
};

#endif // LEETCODE_FINDKPAIRSMALLESTSUMS_HPP
