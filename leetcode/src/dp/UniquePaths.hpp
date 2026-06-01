#ifndef UNIQUE_PATHS_HPP
#define UNIQUE_PATHS_HPP

#include <algorithm>
#include <vector>

using namespace std;

// LeetCode 62, medium, tags: math, dynamic programming, combinatorics.
class UniquePaths {
public:
    // O(mn) time, O(min(m,n)) space. Rolling 1D DP.
    static int dp(int m, int n) {
        if (m > n) swap(m, n);
        vector<int> row(m + 1, 0); // row[0] dummy
        row[1] = 1;
        for (int i = 0; i < n; i++)        // O(n)
            for (int j = 1; j <= m; j++)    // O(m)
                row[j] += row[j - 1];
        return row[m];
    }

    // O(min(m,n)) time, O(1) space. Combinatorics: C(m+n-2, m-1).
    static int combination(int m, int n) {
        if (m > n) swap(m, n);
        long res = 1;
        for (int i = m + n - 2, j = 1; i >= n; i--, j++) // O(min(m,n))
            res = res * i / j;
        return (int) res;
    }
};

#endif
