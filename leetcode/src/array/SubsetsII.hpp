#ifndef SUBSETS_II_HPP
#define SUBSETS_II_HPP
#include <algorithm>
#include <vector>

using namespace std;

class Solution90 {
public:
    // Backtracking with duplicate skipping: O(n*2^n) time, O(n) space (recursion depth)
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());            // sort to group duplicates
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }

    // Iterative cascading for duplicates: O(n*2^n) time and space
    vector<vector<int>> subsetsWithDupCascade(vector<int>& nums) {
        sort(nums.begin(), nums.end());            // sort to group duplicates
        vector<vector<int>> res = {{}};            // start with empty subset
        int prevSize = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int start = 0;
            if (i > 0 && nums[i] == nums[i - 1]) {
                start = prevSize;                  // only extend subsets added in last round
            }
            prevSize = res.size();                 // record size before adding new subsets
            for (int j = start; j < prevSize; j++) { // O(2^n) subsets at most
                vector<int> subset = res[j];
                subset.push_back(nums[i]);         // extend with current element
                res.push_back(std::move(subset));
            }
        }
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);                       // every node is a valid subset
        for (int i = start; i < (int)nums.size(); i++) { // O(n) branches
            if (i > start && nums[i] == nums[i - 1]) continue; // skip duplicates at same level
            path.push_back(nums[i]);               // choose
            backtrack(nums, i + 1, path, res);     // explore
            path.pop_back();                       // un-choose
        }
    }
};

#endif
