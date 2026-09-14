#include "gtest/gtest.h"
#include "sliding/FruitIntoBaskets.hpp"

TEST(sliding, fruit_into_baskets) {
    EXPECT_EQ(3, FruitIntoBaskets::totalFruit({1, 2, 1}));
    EXPECT_EQ(3, FruitIntoBaskets::totalFruit({0, 1, 2, 2}));
    EXPECT_EQ(4, FruitIntoBaskets::totalFruit({1, 2, 3, 2, 2}));
    EXPECT_EQ(1, FruitIntoBaskets::totalFruit({5}));
    EXPECT_EQ(5, FruitIntoBaskets::totalFruit({3, 3, 3, 3, 3}));
    EXPECT_EQ(4, FruitIntoBaskets::totalFruit({1, 2, 1, 2}));
    EXPECT_EQ(5, FruitIntoBaskets::totalFruit({1, 2, 1, 2, 1}));
    EXPECT_EQ(5, FruitIntoBaskets::totalFruit({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}));
}

TEST(sliding, fruit_into_baskets2) {
    EXPECT_EQ(3, FruitIntoBaskets::totalFruit2({1, 2, 1}));
    EXPECT_EQ(3, FruitIntoBaskets::totalFruit2({0, 1, 2, 2}));
    EXPECT_EQ(4, FruitIntoBaskets::totalFruit2({1, 2, 3, 2, 2}));
    EXPECT_EQ(1, FruitIntoBaskets::totalFruit2({5}));
    EXPECT_EQ(5, FruitIntoBaskets::totalFruit2({3, 3, 3, 3, 3}));
    EXPECT_EQ(4, FruitIntoBaskets::totalFruit2({1, 2, 1, 2}));
    EXPECT_EQ(5, FruitIntoBaskets::totalFruit2({1, 2, 1, 2, 1}));
    EXPECT_EQ(5, FruitIntoBaskets::totalFruit2({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}));
}
