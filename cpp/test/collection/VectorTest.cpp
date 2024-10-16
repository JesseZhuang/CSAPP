#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <numeric> // iota https://stackoverflow.com/questions/9244879/what-does-iota-of-stdiota-stand-for

using namespace std;

int binarySearch(vector<int> &vec, int target) // vec must be sorted, pass by reference
{
    auto left = vec.begin(), right = vec.end();
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (target < *mid)
            right = mid - 1;
        else if (target > *mid)
            left = mid + 1;
        else
            return mid - vec.begin();
    }
    return -(left - vec.begin() + 1);
}


TEST(vector, init) {
    vector<int> v1(10);     // default init to 0
    ASSERT_EQ(v1[0], 0);
    vector<string> svec(3); // default init empty strings
    ASSERT_EQ("", svec[0]);
    vector<int> v2{10};     // 1 element with value 10
    ASSERT_EQ(1, v2.size());
    ASSERT_EQ(10, v2[0]);
    vector<int> v3(10, 1);  // ten elements with value 1
    ASSERT_EQ(v3[2], 1);
    vector<int> v4{10, 1};  // two elements
    ASSERT_EQ(v4.size(), 2);
    int int_arr[] = {0, 1, 2, 3, 4};
    vector<int> ivec(begin(int_arr), end(int_arr));
    ASSERT_EQ(4, ivec[4]);
    vector<int> subVec(int_arr + 1, int_arr + 4);
    ASSERT_EQ(1, subVec[0]);
}


TEST(vector, iteration) {
    vector<int> v1{0, 1, 2};
    for (int &a: v1) a += 1; // modify ok, add or remove not allowed during iteration
    vector<int> v2{1, 2, 3};
    ASSERT_EQ(v2, v1);
    vector<int> v5(3);
    iota(begin(v5), end(v5), 1); // natural numbers starting from 1
    vector<int> v6{1, 2, 3};
    for (int i = 0; i < v6.size(); i++) ASSERT_EQ(v6[i], v5[i]);
    int i = 0;
    for (auto it = v5.begin(); it != v5.end(); ++it) {
        ASSERT_EQ(v6[i], *it);
        ASSERT_EQ(it - v5.begin(), i);
        i++;
    }
}

TEST(vector, search) {
    vector<int> v1{1, 2, 4, 5};
    ASSERT_EQ(binarySearch(v1, 2), 1);
    int i = binarySearch(v1, 3);
    ASSERT_EQ(~i, 2); // negate to get insertion index if not present
}
