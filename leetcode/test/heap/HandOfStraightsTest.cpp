#include "gtest/gtest.h"
#include "heap/HandOfStraights.hpp"

TEST(heap, hand_of_straights) {
    Solution846 sol;

    vector<int> h1 = {1,2,3,6,2,3,4,7,8};
    ASSERT_TRUE(sol.isNStraightHand(h1, 3));

    vector<int> h2 = {1,2,3,4,5};
    ASSERT_FALSE(sol.isNStraightHand(h2, 4));

    vector<int> h3 = {1,2,3};
    ASSERT_TRUE(sol.isNStraightHand(h3, 3));

    vector<int> h4 = {5,3,1,4,2};
    ASSERT_TRUE(sol.isNStraightHand(h4, 1));

    vector<int> h5 = {1,1,2,2,3,3};
    ASSERT_TRUE(sol.isNStraightHand(h5, 3));

    vector<int> h6 = {1,3,5,7};
    ASSERT_FALSE(sol.isNStraightHand(h6, 2));

    vector<int> h7 = {1,2,3,4,5,6,7};
    ASSERT_FALSE(sol.isNStraightHand(h7, 4));
}

TEST(heap, hand_of_straights_v2) {
    Solution846V2 sol;

    vector<int> h1 = {1,2,3,6,2,3,4,7,8};
    ASSERT_TRUE(sol.isNStraightHand(h1, 3));

    vector<int> h2 = {1,2,3,4,5};
    ASSERT_FALSE(sol.isNStraightHand(h2, 4));

    vector<int> h3 = {1,2,3};
    ASSERT_TRUE(sol.isNStraightHand(h3, 3));

    vector<int> h4 = {5,3,1,4,2};
    ASSERT_TRUE(sol.isNStraightHand(h4, 1));

    vector<int> h5 = {1,1,2,2,3,3};
    ASSERT_TRUE(sol.isNStraightHand(h5, 3));

    vector<int> h6 = {1,3,5,7};
    ASSERT_FALSE(sol.isNStraightHand(h6, 2));

    vector<int> h7 = {1,2,3,4,5,6,7};
    ASSERT_FALSE(sol.isNStraightHand(h7, 4));
}
