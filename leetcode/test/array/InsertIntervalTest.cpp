#include "gtest/gtest.h"
#include "array/InsertInterval.hpp"

using namespace std;

TEST(array, insert_interval) {
    InsertIntervalSolution sol;

    vector<vector<int>> iv1{{1,3},{6,9}};
    vector<int> ni1{2,5};
    ASSERT_EQ((vector<vector<int>>{{1,5},{6,9}}), sol.insert(iv1, ni1));

    vector<vector<int>> iv2{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> ni2{4,8};
    ASSERT_EQ((vector<vector<int>>{{1,2},{3,10},{12,16}}), sol.insert(iv2, ni2));

    vector<vector<int>> iv3{};
    vector<int> ni3{5,7};
    ASSERT_EQ((vector<vector<int>>{{5,7}}), sol.insert(iv3, ni3));

    vector<vector<int>> iv4{{1,5}};
    vector<int> ni4{2,3};
    ASSERT_EQ((vector<vector<int>>{{1,5}}), sol.insert(iv4, ni4));

    vector<vector<int>> iv5{{1,5}};
    vector<int> ni5{6,8};
    ASSERT_EQ((vector<vector<int>>{{1,5},{6,8}}), sol.insert(iv5, ni5));

    vector<vector<int>> iv6{{1,5}};
    vector<int> ni6{0,0};
    ASSERT_EQ((vector<vector<int>>{{0,0},{1,5}}), sol.insert(iv6, ni6));

    vector<vector<int>> iv7{{1,2},{3,4},{5,6}};
    vector<int> ni7{0,7};
    ASSERT_EQ((vector<vector<int>>{{0,7}}), sol.insert(iv7, ni7));

    vector<vector<int>> iv8{{1,2},{5,6}};
    vector<int> ni8{3,4};
    ASSERT_EQ((vector<vector<int>>{{1,2},{3,4},{5,6}}), sol.insert(iv8, ni8));
}
