#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// solution 1, bottom-up DP with O(n) space. O(n^2) time, O(n) space. n: number of rows.
class TriangleDP {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back()); // O(n) copy last row
        for (int i = n - 2; i >= 0; i--) // O(n) rows bottom to top
            for (int j = 0; j <= i; j++) // O(i) columns
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        return dp[0];
    }
};

// solution 2, in-place bottom-up DP. O(n^2) time, O(1) extra space.
class TriangleInPlace {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) // O(n) rows bottom to top
            for (int j = 0; j <= i; j++) // O(i) columns
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};

#endif //TRIANGLE_HPP
