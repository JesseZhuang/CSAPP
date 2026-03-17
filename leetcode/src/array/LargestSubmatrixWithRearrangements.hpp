#ifndef LEETCODE_LARGESTSUBMATRIXWITHREARRANGEMENTS_HPP
#define LEETCODE_LARGESTSUBMATRIXWITHREARRANGEMENTS_HPP

#include "bits/stdc++.hpp"

using namespace std;

// LeetCode 1727
class Solution {
public:
    // 72ms, 93.48mb
    int largestSubmatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int best = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                heights[j] = matrix[i][j] == 0 ? 0 : heights[j] + 1;
            }
            vector<int> row = heights;
            sort(row.rbegin(), row.rend());
            for (int k = 0; k < n; ++k) {
                if (row[k] == 0) break;
                best = max(best, row[k] * (k + 1));
            }
        }
        return best;
    }
};

class Solution1 {
public:
    // 9ms, 85.21mb
    int largestSubmatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> prev;
        vector<pair<int, int>> cur;
        vector<char> seen(n, 0);
        int best = 0;
        for (int i = 0; i < m; ++i) {
            fill(seen.begin(), seen.end(), 0);
            cur.clear();
            for (const auto &item: prev) {
                int h = item.first, col = item.second;
                if (matrix[i][col] == 1) {
                    cur.push_back({h + 1, col});
                    seen[col] = 1;
                }
            }
            for (int col = 0; col < n; ++col) {
                if (!seen[col] && matrix[i][col] == 1) {
                    cur.push_back({1, col});
                }
            }
            for (int k = 0; k < static_cast<int>(cur.size()); ++k) {
                best = max(best, cur[k].first * (k + 1));
            }
            prev.swap(cur);
        }
        return best;
    }
};

#endif //LEETCODE_LARGESTSUBMATRIXWITHREARRANGEMENTS_HPP
