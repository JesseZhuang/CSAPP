#include "gtest/gtest.h"
#include "hash/CheckIfNDoubleExist.hpp"

TEST(hash, check_if_n_double_exist) {
    CheckIfNDoubleExist sol;
    vector<int> a1{10, 2, 5, 3};
    ASSERT_TRUE(sol.checkIfExist(a1));
    vector<int> a2{3, 1, 7, 11};
    ASSERT_FALSE(sol.checkIfExist(a2));
}
