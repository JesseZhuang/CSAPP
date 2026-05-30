#ifndef SUBSETS_HPP
#define SUBSETS_HPP
#include <vector>

using namespace std;

class Solution78 {
public:
    // Backtracking: O(n*2^n) time, O(n) space (recursion depth)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }

    // Bitmask: O(n*2^n) time and space
    vector<vector<int>> subsetsBitmask(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;                        // 2^n subsets
        vector<vector<int>> res;
        res.reserve(total);
        for (int mask = 0; mask < total; mask++) { // enumerate all masks
            vector<int> subset;
            for (int i = 0; i < n; i++) {          // O(n) per mask
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(std::move(subset));
        }
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);                       // every node is a valid subset
        for (int i = start; i < (int)nums.size(); i++) { // O(n) branches
            path.push_back(nums[i]);               // choose
            backtrack(nums, i + 1, path, res);     // explore (i+1: no reuse)
            path.pop_back();                       // un-choose
        }
    }
};

#endif
