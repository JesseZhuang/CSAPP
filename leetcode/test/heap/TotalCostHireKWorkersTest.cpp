#include "heap/TotalCostHireKWorkers.hpp"
#include <gtest/gtest.h>

TEST(heap, total_cost_hire_k_workers) {
    SolutionTotalCostHireKWorkers sol;

    vector<int> c1 = {17,12,10,2,7,2,11,20,8};
    EXPECT_EQ(sol.totalCost(c1, 3, 4), 11);

    vector<int> c2 = {1,2,4,1};
    EXPECT_EQ(sol.totalCost(c2, 3, 3), 4);

    vector<int> c3 = {5};
    EXPECT_EQ(sol.totalCost(c3, 1, 1), 5);

    vector<int> c4 = {3,3,3,3};
    EXPECT_EQ(sol.totalCost(c4, 2, 2), 6);

    vector<int> c5 = {10,1,10,1};
    EXPECT_EQ(sol.totalCost(c5, 2, 3), 2);

    vector<int> c6 = {2,1,3};
    EXPECT_EQ(sol.totalCost(c6, 3, 1), 6);

    vector<int> c7 = {5,4,3,2,1};
    EXPECT_EQ(sol.totalCost(c7, 3, 10), 6);
}

TEST(heap, total_cost_hire_k_workers_v2) {
    SolutionTotalCostHireKWorkers2 sol;

    vector<int> c1 = {17,12,10,2,7,2,11,20,8};
    EXPECT_EQ(sol.totalCost(c1, 3, 4), 11);

    vector<int> c2 = {1,2,4,1};
    EXPECT_EQ(sol.totalCost(c2, 3, 3), 4);

    vector<int> c3 = {5};
    EXPECT_EQ(sol.totalCost(c3, 1, 1), 5);

    vector<int> c4 = {3,3,3,3};
    EXPECT_EQ(sol.totalCost(c4, 2, 2), 6);

    vector<int> c5 = {10,1,10,1};
    EXPECT_EQ(sol.totalCost(c5, 2, 3), 2);

    vector<int> c6 = {2,1,3};
    EXPECT_EQ(sol.totalCost(c6, 3, 1), 6);

    vector<int> c7 = {5,4,3,2,1};
    EXPECT_EQ(sol.totalCost(c7, 3, 10), 6);
}
