#include "gtest/gtest.h"
#include <tuple>

using namespace std;

TEST(tuple, index_unpack_tuple) {
    tuple<int, int> t1{1, 2};
    ASSERT_EQ(1, get<0>(t1));
    ASSERT_EQ(2, get<1>(t1));
    auto [t11, t12] = t1; // structured binding
    ASSERT_EQ(t11, 1);
    int t21, t22;
    tie(t21, t22) = t1;
    ASSERT_EQ(t22, 2);
}