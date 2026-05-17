#ifndef LEETCODE_PERMUTATIONS_HPP
#define LEETCODE_PERMUTATIONS_HPP

#include <algorithm>
#include <vector>

using namespace std;

// LeetCode 46 — Permutations
// Given an array of distinct integers, return all possible permutations.
class SolutionPermutations {
public:
    // Approach 1: Backtracking with swap
    // Time: O(n * n!), Space: O(n) recursion depth
    vector<vector<int>> permuteSwap(vector<int> &nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

    // Approach 2: Iterative insertion
    // Time: O(n * n!), Space: O(1) extra (not counting result)
    vector<vector<int>> permuteInsert(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        result.push_back({nums[0]});
        for (int i = 1; i < (int)nums.size(); i++) {
            vector<vector<int>> next;
            for (auto &perm : result) {
                // Insert nums[i] at every position 0..perm.size()
                for (int j = 0; j <= (int)perm.size(); j++) {
                    vector<int> newPerm(perm);
                    newPerm.insert(newPerm.begin() + j, nums[i]);
                    next.push_back(move(newPerm));
                }
            }
            result = move(next);
        }
        return result;
    }

private:
    void backtrack(vector<int> &nums, int begin, vector<vector<int>> &result) {
        if (begin == (int)nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < (int)nums.size(); i++) {
            swap(nums[begin], nums[i]);
            backtrack(nums, begin + 1, result);
            swap(nums[begin], nums[i]);
        }
    }
};

#endif //LEETCODE_PERMUTATIONS_HPP
