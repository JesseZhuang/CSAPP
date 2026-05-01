#include "gtest/gtest.h"
#include "array/MinimizedMaxProducts.hpp"
#include <vector>

using namespace std;

TEST(array, minimized_max_products) {
    vector<int> q1{11, 6};
    EXPECT_EQ(MinimizedMaxProducts::minimizedMaximum(6, q1), 3);

    vector<int> q2{15, 10, 10};
    EXPECT_EQ(MinimizedMaxProducts::minimizedMaximum(7, q2), 5);

    vector<int> q3{100000};
    EXPECT_EQ(MinimizedMaxProducts::minimizedMaximum(1, q3), 100000);
}
