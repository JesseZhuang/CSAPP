#include "../../src/array/FindAllDuplicates.hpp"
#include "gtest/gtest.h"

TEST(array, find_all_duplicates) {
    vector<int> v1 = {4, 3, 2, 7, 8, 2, 3, 1};
    auto r1 = Solution442::findDuplicates(v1);
    sort(r1.begin(), r1.end());
    EXPECT_EQ(r1, vector<int>({2, 3}));

    vector<int> v2 = {1, 1, 2};
    auto r2 = Solution442::findDuplicates(v2);
    sort(r2.begin(), r2.end());
    EXPECT_EQ(r2, vector<int>({1}));

    vector<int> v3 = {1};
    auto r3 = Solution442::findDuplicates(v3);
    EXPECT_EQ(r3, vector<int>({}));

    vector<int> v4 = {1, 2, 1, 2};
    auto r4 = Solution442::findDuplicates(v4);
    sort(r4.begin(), r4.end());
    EXPECT_EQ(r4, vector<int>({1, 2}));

    vector<int> v5 = {2, 2};
    auto r5 = Solution442::findDuplicates(v5);
    sort(r5.begin(), r5.end());
    EXPECT_EQ(r5, vector<int>({2}));

    vector<int> v6 = {1, 2, 3, 4, 5};
    auto r6 = Solution442::findDuplicates(v6);
    EXPECT_EQ(r6, vector<int>({}));

    vector<int> v7 = {1, 3, 4, 2, 1, 4};
    auto r7 = Solution442::findDuplicates(v7);
    sort(r7.begin(), r7.end());
    EXPECT_EQ(r7, vector<int>({1, 4}));
}

TEST(array, find_all_duplicates_cyclic_sort) {
    vector<int> v1 = {4, 3, 2, 7, 8, 2, 3, 1};
    auto r1 = Solution442::findDuplicatesCyclicSort(v1);
    sort(r1.begin(), r1.end());
    EXPECT_EQ(r1, vector<int>({2, 3}));

    vector<int> v2 = {1, 1, 2};
    auto r2 = Solution442::findDuplicatesCyclicSort(v2);
    sort(r2.begin(), r2.end());
    EXPECT_EQ(r2, vector<int>({1}));

    vector<int> v3 = {1};
    auto r3 = Solution442::findDuplicatesCyclicSort(v3);
    EXPECT_EQ(r3, vector<int>({}));

    vector<int> v4 = {1, 2, 1, 2};
    auto r4 = Solution442::findDuplicatesCyclicSort(v4);
    sort(r4.begin(), r4.end());
    EXPECT_EQ(r4, vector<int>({1, 2}));

    vector<int> v5 = {2, 2};
    auto r5 = Solution442::findDuplicatesCyclicSort(v5);
    sort(r5.begin(), r5.end());
    EXPECT_EQ(r5, vector<int>({2}));

    vector<int> v6 = {1, 2, 3, 4, 5};
    auto r6 = Solution442::findDuplicatesCyclicSort(v6);
    EXPECT_EQ(r6, vector<int>({}));

    vector<int> v7 = {1, 3, 4, 2, 1, 4};
    auto r7 = Solution442::findDuplicatesCyclicSort(v7);
    sort(r7.begin(), r7.end());
    EXPECT_EQ(r7, vector<int>({1, 4}));
}
