#include "gtest/gtest.h"
#include "array/CountSubmatricesWithTopLeftElement.hpp"

#include <vector>

using namespace std;

TEST(array, count_submatrices_with_top_left_element) {
    Solution tbt;
    vector<vector<vector<int>>> cases = {
            {{1, 1}, {1, 1}},
            {{5}},
            {{1, 2, 3}, {4, 5, 6}},
            {{0, 0}, {0, 0}},
            {{3, 1, 1}, {1, 1, 1}}
    };
    vector<int> ks = {2, 4, 6, 0, 4};
    vector<int> expected = {3, 0, 4, 4, 3};

    for (int i = 0; i < cases.size(); ++i) {
        ASSERT_EQ(expected[i], tbt.resSubmatrices(cases[i], ks[i]));
    }
}
