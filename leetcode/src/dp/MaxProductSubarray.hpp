#ifndef MAXPRODUCTSUBARRAY_HPP
#define MAXPRODUCTSUBARRAY_HPP

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    /// Kadane's variant. O(n) time, O(1) space.
    int maxProduct(vector<int> &nums) {
        int maxHere = 1, minHere = 1, res = INT_MIN;
        for (int n: nums) {
            int p1 = maxHere * n, p2 = minHere * n; // compute before update
            maxHere = max({n, p1, p2}); // O(1)
            minHere = min({n, p1, p2}); // O(1)
            res = max(res, maxHere);    // O(1)
        } // outer loop O(n)
        return res;
    }
};

#endif //MAXPRODUCTSUBARRAY_HPP
