#include "gtest/gtest.h"
#include "hash/MaxNumberOfKSumPairs.hpp"
#include <vector>
using namespace std;

TEST(hash, max_number_of_k_sum_pairs) {
    Solution sol;

    // Example 1: [1,2,3,4] k=5 -> 2
    vector<int> v1{1, 2, 3, 4};
    ASSERT_EQ(2, sol.maxOperations(v1, 5));
    vector<int> v1b{1, 2, 3, 4};
    ASSERT_EQ(2, sol.maxOperationsTwoPtr(v1b, 5));

    // Example 2: [3,1,3,4,3] k=6 -> 1
    vector<int> v2{3, 1, 3, 4, 3};
    ASSERT_EQ(1, sol.maxOperations(v2, 6));
    vector<int> v2b{3, 1, 3, 4, 3};
    ASSERT_EQ(1, sol.maxOperationsTwoPtr(v2b, 6));

    // No pairs: [1,2,3] k=10 -> 0
    vector<int> v3{1, 2, 3};
    ASSERT_EQ(0, sol.maxOperations(v3, 10));
    vector<int> v3b{1, 2, 3};
    ASSERT_EQ(0, sol.maxOperationsTwoPtr(v3b, 10));

    // All pairs: [1,5,2,4,3,3] k=6 -> 3
    vector<int> v4{1, 5, 2, 4, 3, 3};
    ASSERT_EQ(3, sol.maxOperations(v4, 6));
    vector<int> v4b{1, 5, 2, 4, 3, 3};
    ASSERT_EQ(3, sol.maxOperationsTwoPtr(v4b, 6));

    // Duplicates: [2,2,2,2] k=4 -> 2
    vector<int> v5{2, 2, 2, 2};
    ASSERT_EQ(2, sol.maxOperations(v5, 4));
    vector<int> v5b{2, 2, 2, 2};
    ASSERT_EQ(2, sol.maxOperationsTwoPtr(v5b, 4));

    // Single element -> 0
    vector<int> v6{5};
    ASSERT_EQ(0, sol.maxOperations(v6, 5));
    vector<int> v6b{5};
    ASSERT_EQ(0, sol.maxOperationsTwoPtr(v6b, 5));

    // Odd count of matching duplicates: [2,2,2] k=4 -> 1
    vector<int> v7{2, 2, 2};
    ASSERT_EQ(1, sol.maxOperations(v7, 4));
    vector<int> v7b{2, 2, 2};
    ASSERT_EQ(1, sol.maxOperationsTwoPtr(v7b, 4));
}
