#ifndef EQUALROWANDCOLUMNPAIRS_HPP
#define EQUALROWANDCOLUMNPAIRS_HPP

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class SolutionEqualRowAndColumnPairs {
public:
    // Expected O(n^2) time and O(n^2) space for row signatures.
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowFrequencies;
        for (const vector<int>& row : grid)
            rowFrequencies[signature(row)]++;

        int pairs = 0;
        vector<int> column(grid.size());
        for (int columnIndex = 0; columnIndex < grid.size(); columnIndex++) {
            for (int rowIndex = 0; rowIndex < grid.size(); rowIndex++)
                column[rowIndex] = grid[rowIndex][columnIndex];
            pairs += rowFrequencies[signature(column)];
        }
        return pairs;
    }

    // O(n^3) time and O(1) space by comparing every row-column pair.
    int equalPairsBruteForce(vector<vector<int>>& grid) {
        int pairs = 0;
        for (int rowIndex = 0; rowIndex < grid.size(); rowIndex++)
            for (int columnIndex = 0; columnIndex < grid.size(); columnIndex++) {
                int elementIndex = 0;
                while (elementIndex < grid.size()
                       && grid[rowIndex][elementIndex] == grid[elementIndex][columnIndex])
                    elementIndex++;
                if (elementIndex == grid.size())
                    pairs++;
            }
        return pairs;
    }

private:
    static string signature(const vector<int>& values) {
        string result;
        for (int value : values)
            result += to_string(value) + ',';
        return result;
    }
};

#endif
