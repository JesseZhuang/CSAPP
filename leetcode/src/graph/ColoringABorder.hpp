#pragma once

#include <queue>
#include <utility>
#include <vector>

using namespace std;

// 1034. Coloring A Border
// O(m*n) time, O(m*n) space.
class ColoringABorder {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalColor = grid[row][col];
        if (originalColor == color) return grid;

        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> cells;
        vector<pair<int, int>> border;
        int directions[] = {0, 1, 0, -1, 0};

        visited[row][col] = true;
        cells.push({row, col});
        while (!cells.empty()) {
            auto [currentRow, currentCol] = cells.front();
            cells.pop();
            bool isBorder = false;

            for (int direction = 0; direction < 4; direction++) {
                int nextRow = currentRow + directions[direction];
                int nextCol = currentCol + directions[direction + 1];
                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) {
                    isBorder = true;
                } else if (grid[nextRow][nextCol] != originalColor) {
                    isBorder = true;
                } else if (!visited[nextRow][nextCol]) {
                    visited[nextRow][nextCol] = true;
                    cells.push({nextRow, nextCol});
                }
            }

            if (isBorder) border.push_back({currentRow, currentCol});
        }

        for (auto [borderRow, borderCol] : border)
            grid[borderRow][borderCol] = color;
        return grid;
    }
};
