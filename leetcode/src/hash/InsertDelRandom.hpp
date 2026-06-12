#ifndef INSERT_DEL_RANDOM_HPP
#define INSERT_DEL_RANDOM_HPP

#include <unordered_map>
#include <vector>
#include <cstdlib>

using namespace std;

/// LeetCode 380, medium, tags: array, hash table, math, design, randomized.
/// Time O(1) average for all operations, Space O(n).
class Solution380 {
public:
    class RandomizedSet {
        vector<int> nums;
        unordered_map<int, int> valToIdx; // val -> index in nums

    public:
        RandomizedSet() {}

        /// Insert val if not present. Return true if inserted, false if already present.
        bool insert(int val) {
            if (valToIdx.count(val)) return false;
            valToIdx[val] = nums.size();
            nums.push_back(val);
            return true;
        }

        /// Remove val if present. Return true if removed, false if not present.
        /// Swap target with last element, then pop_back to maintain O(1).
        bool remove(int val) {
            if (!valToIdx.count(val)) return false;
            int idx = valToIdx[val];
            int last = nums.back();
            nums[idx] = last;
            valToIdx[last] = idx;
            nums.pop_back();
            valToIdx.erase(val);
            return true;
        }

        /// Return a random element with equal probability.
        int getRandom() {
            return nums[rand() % nums.size()];
        }
    };
};

#endif
