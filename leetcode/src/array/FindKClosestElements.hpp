#ifndef LEETCODE_FINDKCLOSESTELEMENTS_HPP
#define LEETCODE_FINDKCLOSESTELEMENTS_HPP

#include <vector>

using namespace std;

// leet 658, binary search for left boundary. O(log(n-k)) time, O(1) space.
class FindKClosestElements {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int l = 0, r = (int) arr.size() - k;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x - arr[mid] > arr[mid + k] - x) l = mid + 1;
            else r = mid;
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};

#endif //LEETCODE_FINDKCLOSESTELEMENTS_HPP
