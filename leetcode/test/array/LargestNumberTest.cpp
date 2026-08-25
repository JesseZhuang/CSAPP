#include "gtest/gtest.h"
#include "array/LargestNumber.hpp"
#include <vector>
#include <string>

using namespace std;

TEST(array, largest_number) {
    Solution179 sol;
    vector<int> v1{10, 2};
    ASSERT_EQ("210", sol.largestNumber(v1));
    vector<int> v2{3, 30, 34, 5, 9};
    ASSERT_EQ("9534330", sol.largestNumber(v2));
    vector<int> v3{0, 0};
    ASSERT_EQ("0", sol.largestNumber(v3));
    vector<int> v4{1};
    ASSERT_EQ("1", sol.largestNumber(v4));
    vector<int> v5{12, 121};
    ASSERT_EQ("12121", sol.largestNumber(v5));
    vector<int> v6{34323, 3432};
    ASSERT_EQ("343234323", sol.largestNumber(v6));
}
