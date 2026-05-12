#include "gtest/gtest.h"
#include "array/RotateImage.hpp"
#include <vector>

using namespace std;

TEST(array, rotate_image_transpose_reflect) {
    Solution48 sol;
    vector<vector<int>> m1{{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(m1);
    ASSERT_EQ((vector<vector<int>>{{7,4,1},{8,5,2},{9,6,3}}), m1);

    vector<vector<int>> m2{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(m2);
    ASSERT_EQ((vector<vector<int>>{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}), m2);

    vector<vector<int>> m3{{1}};
    sol.rotate(m3);
    ASSERT_EQ((vector<vector<int>>{{1}}), m3);

    vector<vector<int>> m4{{1,2},{3,4}};
    sol.rotate(m4);
    ASSERT_EQ((vector<vector<int>>{{3,1},{4,2}}), m4);
}

TEST(array, rotate_image_four_way) {
    Solution48FourWay sol;
    vector<vector<int>> m1{{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(m1);
    ASSERT_EQ((vector<vector<int>>{{7,4,1},{8,5,2},{9,6,3}}), m1);

    vector<vector<int>> m2{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(m2);
    ASSERT_EQ((vector<vector<int>>{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}), m2);

    vector<vector<int>> m3{{1}};
    sol.rotate(m3);
    ASSERT_EQ((vector<vector<int>>{{1}}), m3);

    vector<vector<int>> m4{{1,2},{3,4}};
    sol.rotate(m4);
    ASSERT_EQ((vector<vector<int>>{{3,1},{4,2}}), m4);
}

TEST(array, rotate_image_5x5) {
    Solution48 sol;
    vector<vector<int>> m{
        {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},
        {16,17,18,19,20},{21,22,23,24,25}
    };
    sol.rotate(m);
    ASSERT_EQ((vector<vector<int>>{
        {21,16,11,6,1},{22,17,12,7,2},{23,18,13,8,3},
        {24,19,14,9,4},{25,20,15,10,5}
    }), m);
}
