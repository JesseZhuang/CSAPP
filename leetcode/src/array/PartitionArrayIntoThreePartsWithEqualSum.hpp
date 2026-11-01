#pragma once

#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        // Two linear passes take O(n) time and O(1) extra space.
        const int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) return false;

        const int target = total / 3;
        int sum = 0;
        int parts = 0;
        // Leave at least one element for the third nonempty partition.
        for (size_t i = 0; i + 1 < arr.size(); ++i) {
            sum += arr[i];
            if (sum == target) {
                ++parts;
                if (parts == 2) return true;
                sum = 0;
            }
        }
        return false;
    }
};
