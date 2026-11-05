#ifndef CLIMBINGSTAIRS_HPP
#define CLIMBINGSTAIRS_HPP

class Solution {
public:
    // DP with the previous two counts. O(n) time, O(1) space.
    int climbStairs(int n) {
        int previous = 1, current = 1;
        for (int step = 2; step <= n; ++step) {
            int next = previous + current;
            previous = current;
            current = next;
        }
        return current;
    }
};

#endif // CLIMBINGSTAIRS_HPP
