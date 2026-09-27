#include "gtest/gtest.h"
#include "array/RotateArray.hpp"
#include <vector>

using namespace std;

TEST(array, rotate_array_triple_reverse) {
    Solution189 sol;

    vector<int> v1{1,2,3,4,5,6,7};
    sol.rotate(v1, 3);
    ASSERT_EQ((vector<int>{5,6,7,1,2,3,4}), v1);

    vector<int> v2{-1,-100,3,99};
    sol.rotate(v2, 2);
    ASSERT_EQ((vector<int>{3,99,-1,-100}), v2);

    vector<int> v3{1};
    sol.rotate(v3, 0);
    ASSERT_EQ((vector<int>{1}), v3);

    vector<int> v4{1};
    sol.rotate(v4, 1);
    ASSERT_EQ((vector<int>{1}), v4);

    vector<int> v5{1,2};
    sol.rotate(v5, 1);
    ASSERT_EQ((vector<int>{2,1}), v5);

    vector<int> v6{1,2};
    sol.rotate(v6, 2);
    ASSERT_EQ((vector<int>{1,2}), v6);

    vector<int> v7{1,2};
    sol.rotate(v7, 3);
    ASSERT_EQ((vector<int>{2,1}), v7);

    vector<int> v8{1,2,3,4,5,6,7};
    sol.rotate(v8, 0);
    ASSERT_EQ((vector<int>{1,2,3,4,5,6,7}), v8);

    vector<int> v9{1,2,3,4,5,6,7};
    sol.rotate(v9, 7);
    ASSERT_EQ((vector<int>{1,2,3,4,5,6,7}), v9);

    vector<int> v10{1,2,3,4,5,6,7};
    sol.rotate(v10, 10);
    ASSERT_EQ((vector<int>{5,6,7,1,2,3,4}), v10);
}

TEST(array, rotate_array_extra_array) {
    Solution189ExtraArray sol;

    vector<int> v1{1,2,3,4,5,6,7};
    sol.rotate(v1, 3);
    ASSERT_EQ((vector<int>{5,6,7,1,2,3,4}), v1);

    vector<int> v2{-1,-100,3,99};
    sol.rotate(v2, 2);
    ASSERT_EQ((vector<int>{3,99,-1,-100}), v2);

    vector<int> v3{1};
    sol.rotate(v3, 0);
    ASSERT_EQ((vector<int>{1}), v3);

    vector<int> v4{1};
    sol.rotate(v4, 1);
    ASSERT_EQ((vector<int>{1}), v4);

    vector<int> v5{1,2};
    sol.rotate(v5, 1);
    ASSERT_EQ((vector<int>{2,1}), v5);

    vector<int> v6{1,2};
    sol.rotate(v6, 2);
    ASSERT_EQ((vector<int>{1,2}), v6);

    vector<int> v7{1,2};
    sol.rotate(v7, 3);
    ASSERT_EQ((vector<int>{2,1}), v7);

    vector<int> v8{1,2,3,4,5,6,7};
    sol.rotate(v8, 0);
    ASSERT_EQ((vector<int>{1,2,3,4,5,6,7}), v8);

    vector<int> v9{1,2,3,4,5,6,7};
    sol.rotate(v9, 7);
    ASSERT_EQ((vector<int>{1,2,3,4,5,6,7}), v9);

    vector<int> v10{1,2,3,4,5,6,7};
    sol.rotate(v10, 10);
    ASSERT_EQ((vector<int>{5,6,7,1,2,3,4}), v10);
}
