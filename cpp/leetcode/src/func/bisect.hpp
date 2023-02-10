#ifndef LEET_CODE_BISECT_HPP
#define LEET_CODE_BISECT_HPP

#include <vector>

using namespace std;

int bisect(vector<int> &nums, int target, int left, int right) {
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
        else return mid;
    }
    return -left - 1; // if not existing, caller can ~result to get the index to insert
}

int bisect(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    return bisect(nums, target, left, right);
}

#endif //LEET_CODE_BISECT_HPP
