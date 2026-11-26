#ifndef LEETCODE_SINGLENUMBER_HPP
#define LEETCODE_SINGLENUMBER_HPP

#include <unordered_set>
#include <vector>

class Solution136 {
public:
    // XOR cancels each pair. O(n) time and O(1) extra space.
    int singleNumber(const std::vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }

    // Remove each value on its second occurrence. O(n) expected time and O(n) extra space.
    int singleNumberHashSet(const std::vector<int>& nums) {
        std::unordered_set<int> unpaired;
        for (int num : nums) {
            const auto [it, inserted] = unpaired.insert(num);
            if (!inserted) {
                unpaired.erase(it);
            }
        }
        return *unpaired.begin();
    }
};

#endif // LEETCODE_SINGLENUMBER_HPP
