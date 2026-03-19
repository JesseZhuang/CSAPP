#include "gtest/gtest.h"
#include "array/CountSubmatricesEqualFreqXY.hpp"

#include <vector>

using namespace std;

TEST(array, count_submatrices_equal_freq_xy) {
    CountSubmatricesEqualFreqXY sol;
    vector<pair<vector<vector<char>>, int>> cases = {
            {{{'X', 'Y', '.'}, {'Y', '.', '.'}}, 3},
            {{{'X', 'X'}, {'X', 'Y'}}, 0},
            {{{'.', '.'}}, 0},
            {{{'X', 'Y'}}, 1},
            {{{'X'}, {'Y'}}, 1},
            {{{'Y', 'X'}}, 1},
            {{{'X'}}, 0},
            {{{'Y'}}, 0},
            {{{'.', 'X', '.', 'Y'}}, 1},
            {{{'X', '.', 'Y', '.', 'X', 'Y'}}, 3},
            {{{'X', 'Y'}, {'Y', 'X'}}, 3},
            {{{'.', '.'}, {'.', '.'}}, 0},
            {{{'X', 'Y', 'X'}, {'Y', 'X', 'Y'}, {'X', 'Y', 'X'}}, 5},
    };

    for (const auto &[grid, want] : cases) {
        vector<vector<char>> g = grid;
        ASSERT_EQ(want, sol.numberOfSubmatrices(g));
    }
}
