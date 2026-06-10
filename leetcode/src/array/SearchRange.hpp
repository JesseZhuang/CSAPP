#pragma once
#include <vector>
using namespace std;

class SearchRange {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int left = findLeft(nums, target);
        if (left == -1) {
            return {-1, -1};
        }

        int right = findRight(nums, target);
        return {left, right};
    }

private:
    // Find the leftmost (first) occurrence of target
    int findLeft(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result = mid;
                right = mid - 1;  // Continue searching left
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    // Find the rightmost (last) occurrence of target
    int findRight(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result = mid;
                left = mid + 1;  // Continue searching right
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
