#ifndef LEETCODE_FINDDIFFERENCEOFTWOARRAYS_HPP
#define LEETCODE_FINDDIFFERENCEOFTWOARRAYS_HPP

#include <unordered_set>
#include <vector>

class Solution2215 {
public:
    std::vector<std::vector<int>> findDifference(const std::vector<int>& nums1,
                                                  const std::vector<int>& nums2) {
        const std::unordered_set<int> first(nums1.begin(), nums1.end());
        const std::unordered_set<int> second(nums2.begin(), nums2.end());
        std::vector<std::vector<int>> result(2);

        for (int value : first) {
            if (!second.contains(value)) {
                result[0].push_back(value);
            }
        }
        for (int value : second) {
            if (!first.contains(value)) {
                result[1].push_back(value);
            }
        }

        return result;
    }
};

#endif // LEETCODE_FINDDIFFERENCEOFTWOARRAYS_HPP
