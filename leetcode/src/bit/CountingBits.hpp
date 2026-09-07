#ifndef LEETCODE_COUNTINGBITS_HPP
#define LEETCODE_COUNTINGBITS_HPP

#include <vector>

using namespace std;

class Solution338 {
public:
    // DP with bit shift: ans[i] = ans[i >> 1] + (i & 1)
    // Time: O(n), Space: O(1) extra (output array not counted)
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
            ans[i] = ans[i >> 1] + (i & 1); // right-shift reuses sub-problem
        return ans;
    }

    // DP with Brian Kernighan: ans[i] = ans[i & (i-1)] + 1
    // Time: O(n), Space: O(1) extra
    vector<int> countBits2(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
            ans[i] = ans[i & (i - 1)] + 1; // drop lowest set bit
        return ans;
    }
};

#endif //LEETCODE_COUNTINGBITS_HPP
