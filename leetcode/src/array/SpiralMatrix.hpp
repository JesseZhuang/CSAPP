#ifndef SPIRAL_MATRIX_HPP
#define SPIRAL_MATRIX_HPP

#include <vector>

using namespace std;

// LeetCode 54, medium, tags: array, matrix, simulation.
// O(m*n) time, O(1) space.
class SpiralMatrix {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int limits[2] = {n, m - 1};
        vector<int> res;
        int d = 0, r = 0, c = -1;
        while (limits[d % 2] > 0) {
            for (int i = 0; i < limits[d % 2]; i++) {
                r += dirs[d][0];
                c += dirs[d][1];
                res.push_back(matrix[r][c]);
            }
            limits[d % 2]--;
            d = (d + 1) % 4;
        }
        return res;
    }
};

#endif
