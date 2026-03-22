#include "gtest/gtest.h"
#include "graph/MaxCandiesBoxes.hpp"
#include <vector>

using namespace std;

TEST(graph, max_candies_boxes) {
    Solution tbt;

    vector<int> s1{1, 0, 1, 0};
    vector<int> c1{7, 5, 4, 100};
    vector<vector<int>> k1{{}, {}, {1}, {}};
    vector<vector<int>> cb1{{1, 2}, {3}, {}, {}};
    vector<int> i1{0};
    ASSERT_EQ(16, tbt.maxCandies(s1, c1, k1, cb1, i1));

    vector<int> s2{1, 0, 0, 0, 0, 0};
    vector<int> c2{1, 1, 1, 1, 1, 1};
    vector<vector<int>> k2{{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    vector<vector<int>> cb2{{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    vector<int> i2{0};
    ASSERT_EQ(6, tbt.maxCandies(s2, c2, k2, cb2, i2));

    vector<int> s3{1, 1};
    vector<int> c3{10, 20};
    vector<vector<int>> k3{{}, {}};
    vector<vector<int>> cb3{{}, {}};
    vector<int> i3{};
    ASSERT_EQ(0, tbt.maxCandies(s3, c3, k3, cb3, i3));

    vector<int> s4{1};
    vector<int> c4{42};
    vector<vector<int>> k4{{}};
    vector<vector<int>> cb4{{}};
    vector<int> i4{0};
    ASSERT_EQ(42, tbt.maxCandies(s4, c4, k4, cb4, i4));

    vector<int> s5{0};
    vector<int> c5{42};
    vector<vector<int>> k5{{}};
    vector<vector<int>> cb5{{}};
    vector<int> i5{0};
    ASSERT_EQ(0, tbt.maxCandies(s5, c5, k5, cb5, i5));

    vector<int> s6{1, 0, 0};
    vector<int> c6{1, 2, 3};
    vector<vector<int>> k6{{1}, {2}, {}};
    vector<vector<int>> cb6{{1}, {2}, {}};
    vector<int> i6{0};
    ASSERT_EQ(6, tbt.maxCandies(s6, c6, k6, cb6, i6));

    vector<int> s7{1, 0, 1};
    vector<int> c7{10, 100, 1};
    vector<vector<int>> k7{{1}, {}, {}};
    vector<vector<int>> cb7{{}, {}, {1}};
    vector<int> i7{0, 2};
    ASSERT_EQ(111, tbt.maxCandies(s7, c7, k7, cb7, i7));

    vector<int> s8{1, 0, 0};
    vector<int> c8{5, 10, 100};
    vector<vector<int>> k8{{}, {}, {}};
    vector<vector<int>> cb8{{1}, {}, {}};
    vector<int> i8{0};
    ASSERT_EQ(5, tbt.maxCandies(s8, c8, k8, cb8, i8));

    vector<int> s9{1, 1, 0};
    vector<int> c9{1, 2, 3};
    vector<vector<int>> k9{{2}, {2}, {}};
    vector<vector<int>> cb9{{1}, {2}, {}};
    vector<int> i9{0};
    ASSERT_EQ(6, tbt.maxCandies(s9, c9, k9, cb9, i9));

    vector<int> s10{0, 0};
    vector<int> c10{10, 20};
    vector<vector<int>> k10{{1}, {0}};
    vector<vector<int>> cb10{{}, {}};
    vector<int> i10{0, 1};
    ASSERT_EQ(0, tbt.maxCandies(s10, c10, k10, cb10, i10));
}
