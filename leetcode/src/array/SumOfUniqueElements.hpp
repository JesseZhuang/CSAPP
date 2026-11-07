#ifndef SUMOFUNIQUEELEMENTS_HPP
#define SUMOFUNIQUEELEMENTS_HPP

#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    // O(n + U) time and O(U) space, where U = 100.
    int sumOfUnique(const vector<int>& nums) {
        array<int, 101> frequency{};
        for (int value : nums) {
            ++frequency[value];
        }

        int sum = 0;
        for (int value = 1; value <= 100; ++value) {
            if (frequency[value] == 1) {
                sum += value;
            }
        }
        return sum;
    }

    // O(n log n) time and O(n) space for the sorted copy.
    int sumOfUniqueBySorting(const vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int sum = 0;
        for (size_t start = 0; start < sorted.size();) {
            size_t end = start + 1;
            while (end < sorted.size() && sorted[end] == sorted[start]) {
                ++end;
            }
            if (end == start + 1) {
                sum += sorted[start];
            }
            start = end;
        }
        return sum;
    }
};

#endif // SUMOFUNIQUEELEMENTS_HPP
