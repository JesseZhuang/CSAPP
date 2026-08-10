#ifndef PERFECTSQUARES_HPP
#define PERFECTSQUARES_HPP
#include <cmath>
#include <vector>

using namespace std;

// solution 1, DP. O(N*sqrt(N)) time, O(N) space.
class PerfectSquaresDP {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};

// solution 2, Math (Lagrange's four-square + Legendre's three-square theorem). O(sqrt(N)) time, O(1) space.
class PerfectSquaresMath {
public:
    int numSquares(int n) {
        // If n is a perfect square
        if (isSquare(n)) return 1;
        // Check if n = 4^a * (8b + 7), then answer is 4 (Legendre's three-square theorem)
        int tmp = n;
        while (tmp % 4 == 0) tmp /= 4;
        if (tmp % 8 == 7) return 4;
        // Check if n can be expressed as sum of two squares
        for (int i = 1; i * i <= n; i++)
            if (isSquare(n - i * i)) return 2;
        // Otherwise answer is 3
        return 3;
    }

private:
    bool isSquare(int n) {
        int s = (int) sqrt(n);
        return s * s == n;
    }
};

#endif //PERFECTSQUARES_HPP
