#include "gtest/gtest.h"
#include "dp/PerfectSquares.hpp"

TEST(dp, perfect_squares_dp) {
    PerfectSquaresDP sol;
    ASSERT_EQ(3, sol.numSquares(12));
    ASSERT_EQ(2, sol.numSquares(13));
    ASSERT_EQ(1, sol.numSquares(1));
    ASSERT_EQ(1, sol.numSquares(4));
    ASSERT_EQ(4, sol.numSquares(7));
    ASSERT_EQ(4, sol.numSquares(15));
    ASSERT_EQ(1, sol.numSquares(100));
    ASSERT_EQ(2, sol.numSquares(2));
    ASSERT_EQ(3, sol.numSquares(3));
    ASSERT_EQ(1, sol.numSquares(10000));
    ASSERT_EQ(4, sol.numSquares(9999));
}

TEST(dp, perfect_squares_math) {
    PerfectSquaresMath sol;
    ASSERT_EQ(3, sol.numSquares(12));
    ASSERT_EQ(2, sol.numSquares(13));
    ASSERT_EQ(1, sol.numSquares(1));
    ASSERT_EQ(1, sol.numSquares(4));
    ASSERT_EQ(4, sol.numSquares(7));
    ASSERT_EQ(4, sol.numSquares(15));
    ASSERT_EQ(1, sol.numSquares(100));
    ASSERT_EQ(2, sol.numSquares(2));
    ASSERT_EQ(3, sol.numSquares(3));
    ASSERT_EQ(1, sol.numSquares(10000));
    ASSERT_EQ(4, sol.numSquares(9999));
}
