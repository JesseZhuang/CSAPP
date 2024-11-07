#include "gtest/gtest.h"
#include "tree/SubstringReversal.hpp"

using namespace std;

TEST(tree, substring_reversal_test) {
    Solution tbt;
    vector<pair<int, int>> op{{3, 4},
                              {4, 7}};
    string res = tbt.reverse_ss("AYBABTU", op);
    ASSERT_EQ("AYAUTBB", res);
}
