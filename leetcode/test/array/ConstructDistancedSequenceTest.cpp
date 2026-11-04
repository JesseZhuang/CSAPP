#include "gtest/gtest.h"
#include "array/ConstructDistancedSequence.hpp"

#include <vector>

using namespace std;

TEST(array, construct_distanced_sequence) {
    EXPECT_EQ(vector<int>({1}), ConstructDistancedSequence::constructDistancedSequence(1));
    EXPECT_EQ(vector<int>({3, 1, 2, 3, 2}),
              ConstructDistancedSequence::constructDistancedSequence(3));
    EXPECT_EQ(vector<int>({5, 3, 1, 4, 3, 5, 2, 4, 2}),
              ConstructDistancedSequence::constructDistancedSequence(5));

    const int n = 20;
    const auto sequence = ConstructDistancedSequence::constructDistancedSequence(n);
    ASSERT_EQ(2 * n - 1, sequence.size());
    vector<vector<int>> positions(n + 1);
    for (int i = 0; i < (int)sequence.size(); ++i) {
        ASSERT_GE(sequence[i], 1);
        ASSERT_LE(sequence[i], n);
        positions[sequence[i]].push_back(i);
    }
    EXPECT_EQ(1u, positions[1].size());
    for (int value = 2; value <= n; ++value) {
        ASSERT_EQ(2u, positions[value].size()) << "value = " << value;
        EXPECT_EQ(value, positions[value][1] - positions[value][0]);
    }
}
