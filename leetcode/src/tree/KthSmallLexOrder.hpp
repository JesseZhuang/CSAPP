#ifndef LEETCODE_KTHSMALLLEXORDER_HPP
#define LEETCODE_KTHSMALLLEXORDER_HPP

#include <algorithm>

using namespace std;

// LeetCode 440
class Solution {
    int n;
public:
    int findKthNumber(int n, int k) {
        this->n = n;
        int cur = 1;
        k--;
        while (k > 0) {
            int steps = cntSteps(cur);
            if (steps <= k) {
                k -= steps;
                cur++;
            } else {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }

    int cntSteps(long cur) {
        long next = cur + 1, n = static_cast<long>(this->n);
        int res = 0;
        while (cur <= n) {
            res += static_cast<int>(min(n + 1, next) - cur);
            cur *= 10;
            next *= 10;
        }
        return res;
    }
};

#endif //LEETCODE_KTHSMALLLEXORDER_HPP
