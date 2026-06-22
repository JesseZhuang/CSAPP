#pragma once
#include <vector>
using namespace std;

class SortColors {
public:
    // Dutch National Flag — single pass O(n) time, O(1) space
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = (int)nums.size() - 1;
        while (mid <= hi) {
            if (nums[mid] == 0) {
                swap(nums[lo++], nums[mid++]);
            } else if (nums[mid] == 1) {
                ++mid;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[hi--]);
            }
        }
    }

    // Counting sort — two pass O(n) time, O(1) space
    void sortColors2(vector<int>& nums) {
        int count[3] = {0, 0, 0};
        for (int x : nums) ++count[x];       // first pass: count
        int idx = 0;
        for (int c = 0; c < 3; ++c)          // second pass: overwrite
            for (int i = 0; i < count[c]; ++i)
                nums[idx++] = c;
    }
};
