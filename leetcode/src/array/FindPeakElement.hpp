#pragma once
#include <vector>
using namespace std;

class FindPeakElement {
public:
    // O(log n) time, O(1) space
    static int findPeakElementBinarySearch(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        // Binary search: move toward the side with a larger neighbor
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;  // peak is to the right
            else
                right = mid;     // peak is at mid or to the left
        }
        return left;
    }

    // O(n) time, O(1) space
    static int findPeakElementLinear(vector<int>& nums) {
        // Linear scan: return first element greater than its next neighbor
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return (int)nums.size() - 1;
    }
};
