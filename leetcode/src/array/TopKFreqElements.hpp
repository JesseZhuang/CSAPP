#ifndef LEETCODE_TOPKFREQELEMENTS_HPP
#define LEETCODE_TOPKFREQELEMENTS_HPP

#include <vector>
#include <unordered_map>

using namespace std;
// LeetCode 347

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        int N = nums.size();
        vector<vector<int>> buk(N + 1);
        unordered_map<int, int> count;
        for (int n: nums) count[n] += 1;
        for (auto e: count) buk[e.second].emplace_back(e.first);
        vector<int> res;
        int i = 0, j = N;
        while (i < k) {
            for (int v: buk[j]) {
                res.emplace_back(v);
                i++;
                if (i == k) return res;
            }
            j--;
        }
        return res;
    }
};

#endif //LEETCODE_TOPKFREQELEMENTS_HPP
