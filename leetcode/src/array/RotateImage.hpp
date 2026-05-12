#ifndef ROTATEIMAGE_HPP
#define ROTATEIMAGE_HPP
#include <vector>
#include <algorithm>

using namespace std;

// Solution 1: Transpose then reflect. O(n^2) time, O(1) space.
class Solution48 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) // O(n^2) transpose
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; i++) // O(n^2) reflect left-right
            for (int j = 0; j < n / 2; j++)
                swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
};

// Solution 2: Rotate four cells at a time, layer by layer. O(n^2) time, O(1) space.
class Solution48FourWay {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) // O(n/2) layers
            for (int j = i; j < n - i - 1; j++) { // O(n) elements per layer
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
    }
};

#endif
