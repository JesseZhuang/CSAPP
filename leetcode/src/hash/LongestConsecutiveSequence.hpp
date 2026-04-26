#ifndef LONGEST_CONSECUTIVE_SEQUENCE_HPP
#define LONGEST_CONSECUTIVE_SEQUENCE_HPP

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/// LeetCode 128, medium, tags: array, hash table, union find.
class Solution128 {
public:
    /// HashSet approach: only start counting from sequence starts (where num-1 not in set).
    /// Time O(n), Space O(n).
    int longestConsecutiveSet(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : numSet) {
            // Only start counting if this is a sequence start
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLen = 1;

                // Count consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLen++;
                }

                maxLen = max(maxLen, currentLen);
            }
        }

        return maxLen;
    }

    /// Union Find approach: union adjacent numbers.
    /// Time O(n * α(n)) ≈ O(n), Space O(n).
    int longestConsecutiveUF(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> parent;
        unordered_map<int, int> size;

        // Initialize each number as its own parent with size 1
        for (int num : nums) {
            if (parent.find(num) == parent.end()) {
                parent[num] = num;
                size[num] = 1;
            }
        }

        // Union adjacent numbers
        for (int num : nums) {
            if (parent.find(num + 1) != parent.end()) {
                unionSets(num, num + 1, parent, size);
            }
        }

        // Find maximum size
        int maxLen = 0;
        for (const auto& [num, sz] : size) {
            maxLen = max(maxLen, sz);
        }

        return maxLen;
    }

private:
    int find(int x, unordered_map<int, int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);  // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y, unordered_map<int, int>& parent,
                   unordered_map<int, int>& size) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);

        if (rootX != rootY) {
            // Union by size
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
};

#endif
