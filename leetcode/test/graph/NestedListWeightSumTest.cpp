#include "graph/NestedListWeightSum.hpp"
#include <gtest/gtest.h>

TEST(graph, nested_list_weight_sum) {
    SolutionNestedListWeightSum sol;

    // Example 1: [[1,1],2,[1,1]] -> 10
    vector<NestedInteger> nl1 = {
        NestedInteger(vector<NestedInteger>{1, 1}),
        NestedInteger(2),
        NestedInteger(vector<NestedInteger>{1, 1}),
    };
    EXPECT_EQ(sol.depthSum(nl1), 10);

    // Example 2: [1,[4,[6]]] -> 27
    vector<NestedInteger> nl2 = {
        NestedInteger(1),
        NestedInteger(vector<NestedInteger>{
            NestedInteger(4),
            NestedInteger(vector<NestedInteger>{NestedInteger(6)}),
        }),
    };
    EXPECT_EQ(sol.depthSum(nl2), 27);

    // Example 3: [0] -> 0
    vector<NestedInteger> nl3 = {NestedInteger(0)};
    EXPECT_EQ(sol.depthSum(nl3), 0);
}
