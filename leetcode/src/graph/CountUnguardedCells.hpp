#ifndef COUNT_UNGUARDED_CELLS_HPP
#define COUNT_UNGUARDED_CELLS_HPP

#include <vector>
using namespace std;

// LeetCode 2257. Simulation. O(mn + g(m+n)) time, O(mn) space.
class CountUnguardedCells {
public:
    static int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        const int GUARD = 2, WALL = 3, GUARDED = 1;
        for (auto& g : guards) grid[g[0]][g[1]] = GUARD;
        for (auto& w : walls) grid[w[0]][w[1]] = WALL;
        int dirs[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& g : guards) {
            for (auto& d : dirs) {
                int nr = g[0] + d[0], nc = g[1] + d[1];
                while (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                       grid[nr][nc] != GUARD && grid[nr][nc] != WALL) {
                    grid[nr][nc] = GUARDED;
                    nr += d[0];
                    nc += d[1];
                }
            }
        }
        int res = 0;
        for (auto& row : grid)
            for (int cell : row)
                if (cell == 0) res++;
        return res;
    }
};

#endif
