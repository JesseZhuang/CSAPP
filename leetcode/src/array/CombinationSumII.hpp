#ifndef COMBINATIONSUMII_HPP
#define COMBINATIONSUMII_HPP
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Solution 1: Backtracking with sort + skip duplicates. O(2^n) time, O(n) space.
class Solution40 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // O(n log n)
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, target, 0, path, res);
        return res;
    }
private:
    void backtrack(vector<int>& c, int remaining, int start, vector<int>& path, vector<vector<int>>& res) {
        if (remaining == 0) { // found valid combination
            res.push_back(path);
            return;
        }
        for (int i = start; i < (int)c.size(); i++) { // O(2^n) total branches
            if (c[i] > remaining) break; // prune: sorted
            if (i > start && c[i] == c[i - 1]) continue; // skip duplicates at same level
            path.push_back(c[i]);
            backtrack(c, remaining - c[i], i + 1, path, res); // i+1: each element used once
            path.pop_back();
        }
    }
};

// Solution 2: Counter-based approach using unordered_map. O(2^n) time, O(n) space.
class Solution40Counter {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> counter; // value -> count
        for (int c : candidates) counter[c]++; // O(n)
        vector<pair<int, int>> counts(counter.begin(), counter.end());
        sort(counts.begin(), counts.end()); // sort by value for deterministic order
        vector<vector<int>> res;
        vector<int> path;
        backtrack(counts, target, 0, path, res);
        return res;
    }
private:
    void backtrack(vector<pair<int,int>>& counts, int remaining, int idx, vector<int>& path, vector<vector<int>>& res) {
        if (remaining == 0) { // found valid combination
            res.push_back(path);
            return;
        }
        for (int i = idx; i < (int)counts.size(); i++) { // iterate unique values
            int val = counts[i].first;
            int freq = counts[i].second;
            if (val > remaining) break; // prune: sorted
            for (int k = 1; k <= freq && k * val <= remaining; k++) { // use 1..freq copies
                path.push_back(val);
                backtrack(counts, remaining - k * val, i + 1, path, res);
            }
            for (int k = min(freq, remaining / val); k > 0; k--) path.pop_back(); // undo all pushes
        }
    }
};

#endif
