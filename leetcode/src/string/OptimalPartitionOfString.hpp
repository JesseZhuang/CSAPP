#pragma once

#include <cstdint>
#include <string>
#include <unordered_set>

namespace optimal_partition_of_string {
class Solution {
public:
    // LeetCode 2405. Expected O(n) time and O(1) space for 26 letters.
    int partitionString(const std::string& s) {
        int partitions = 1;
        std::unordered_set<char> seen;
        for (char letter : s) {
            if (seen.contains(letter)) {
                ++partitions;
                seen.clear();
            }
            seen.insert(letter);
        }
        return partitions;
    }

    // O(n) time and O(1) space with one bit per lowercase letter.
    int partitionStringBitmask(const std::string& s) {
        int partitions = 1;
        std::uint32_t seen = 0;
        for (char letter : s) {
            const std::uint32_t bit = std::uint32_t{1} << (letter - 'a');
            if ((seen & bit) != 0) {
                ++partitions;
                seen = 0;
            }
            seen |= bit;
        }
        return partitions;
    }
};
} // namespace optimal_partition_of_string
