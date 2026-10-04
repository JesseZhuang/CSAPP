#include <gtest/gtest.h>
#include "binary_search/MinimumOperationsToMakeAllArrayElementsEqual.hpp"

TEST(binary_search, minimum_operations_to_make_all_array_elements_equal) {
    Solution solution;

    vector<int> exampleNums = {3, 1, 6, 8};
    vector<int> exampleQueries = {1, 5};
    vector<long long> exampleExpected = {14, 10};
    EXPECT_EQ(exampleExpected, solution.minOperations(exampleNums, exampleQueries));

    vector<int> boundaryNums = {2, 4, 6};
    vector<int> boundaryQueries = {1, 4, 7};
    vector<long long> boundaryExpected = {9, 4, 9};
    EXPECT_EQ(boundaryExpected, solution.minOperations(boundaryNums, boundaryQueries));

    vector<int> duplicateNums = {4, 4, 4};
    vector<int> duplicateQueries = {4, 3, 5};
    vector<long long> duplicateExpected = {0, 3, 3};
    EXPECT_EQ(duplicateExpected, solution.minOperations(duplicateNums, duplicateQueries));

    vector<int> orderedNums = {1, 10, 100};
    vector<int> orderedQueries = {50, 1, 100, 10};
    vector<long long> orderedExpected = {139, 108, 189, 99};
    EXPECT_EQ(orderedExpected, solution.minOperations(orderedNums, orderedQueries));

    vector<int> largeNums(100000, 1000000000);
    vector<int> largeQueries = {1};
    vector<long long> largeExpected = {99999999900000LL};
    EXPECT_EQ(largeExpected, solution.minOperations(largeNums, largeQueries));
}
