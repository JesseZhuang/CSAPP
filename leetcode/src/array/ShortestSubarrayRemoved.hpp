#ifndef SHORTEST_SUBARRAY_REMOVED_HPP
#define SHORTEST_SUBARRAY_REMOVED_HPP

#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 1574. Two pointers. O(n) time, O(1) space.
class ShortestSubarrayRemoved {
public:
    static int findLengthOfShortestSubarray(vector<int>& A) {
        int r = (int)A.size() - 1;
        while (r > 0 && A[r] >= A[r - 1]) r--;
        int res = r, l = 0;
        while (l < r && (l == 0 || A[l - 1] <= A[l])) {
            while (r < (int)A.size() && A[l] > A[r]) r++;
            res = min(res, r - l - 1);
            l++;
        }
        return res;
    }
};

#endif
