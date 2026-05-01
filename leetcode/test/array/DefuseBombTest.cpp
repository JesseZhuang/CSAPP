#include "gtest/gtest.h"
#include "array/DefuseBomb.hpp"
#include <vector>

using namespace std;

TEST(array, defuse_bomb) {
    vector<int> c1{5, 7, 1, 4};
    EXPECT_EQ(DefuseBomb::decrypt(c1, 3), (vector<int>{12, 10, 16, 13}));

    vector<int> c2{1, 2, 3, 4};
    EXPECT_EQ(DefuseBomb::decrypt(c2, 0), (vector<int>{0, 0, 0, 0}));

    vector<int> c3{2, 4, 9, 3};
    EXPECT_EQ(DefuseBomb::decrypt(c3, -2), (vector<int>{12, 5, 6, 13}));
}
