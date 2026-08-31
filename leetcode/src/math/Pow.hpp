#ifndef LEETCODE_POW_HPP
#define LEETCODE_POW_HPP

// leet 50
class Solution50 {
public:
    // iterative binary exponentiation. O(lg n) time, O(1) space.
    double myPow(double x, int n) {
        long long N = n; // avoid overflow when negating INT_MIN
        if (N < 0) { N = -N; x = 1 / x; }
        double pow = 1;
        while (N) { // O(lg n) iterations
            if (N & 1) pow *= x;
            x *= x;
            N >>= 1;
        }
        return pow;
    }

    // recursive binary exponentiation. O(lg n) time and space.
    double myPowRecursive(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) return 1 / x * myPowRecursive(1 / x, -(n + 1)); // O(lg n) recursion depth
        return n % 2 == 0 ? myPowRecursive(x * x, n / 2) : x * myPowRecursive(x * x, n / 2);
    }
};
#endif
