#ifndef LEETCODE_UNIQUENUMBEROFOCCURRENCES_HPP
#define LEETCODE_UNIQUENUMBEROFOCCURRENCES_HPP

#include <array>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    // Expected O(n) time and O(n) space.
    bool uniqueOccurrences(const std::vector<int> &arr) {
        std::unordered_map<int, int> frequencies;
        for (int value : arr) {
            ++frequencies[value];
        }

        std::unordered_set<int> seenFrequencies;
        for (const auto &entry : frequencies) {
            if (!seenFrequencies.insert(entry.second).second) {
                return false;
            }
        }

        return true;
    }

    // O(n + U) time and space, where U is the bounded value range.
    bool uniqueOccurrencesByFrequencyArray(const std::vector<int> &arr) {
        constexpr int minValue = -1000;
        constexpr int maxValue = 1000;
        constexpr int valueRange = maxValue - minValue + 1;
        std::array<int, valueRange> frequencies{};

        for (int value : arr) {
            ++frequencies[value - minValue];
        }

        std::vector<bool> seenFrequencies(arr.size() + 1, false);
        for (int frequency : frequencies) {
            if (frequency > 0) {
                if (seenFrequencies[frequency]) {
                    return false;
                }
                seenFrequencies[frequency] = true;
            }
        }

        return true;
    }
};

#endif // LEETCODE_UNIQUENUMBEROFOCCURRENCES_HPP
