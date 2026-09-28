#include "gtest/gtest.h"
#include "dp/MinCostTickets.hpp"

TEST(dp, min_cost_tickets) {
    MinCostTicketsDP sol;
    vector<int> d1 = {1, 4, 6, 7, 8, 20}, c1 = {2, 7, 15};
    ASSERT_EQ(11, sol.mincostTickets(d1, c1));
    vector<int> d2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, c2 = {2, 7, 15};
    ASSERT_EQ(17, sol.mincostTickets(d2, c2));
    vector<int> d3 = {1}, c3 = {2, 7, 15};
    ASSERT_EQ(2, sol.mincostTickets(d3, c3));
    vector<int> d4 = {1, 2, 3, 4, 5, 6, 7}, c4 = {2, 7, 15};
    ASSERT_EQ(7, sol.mincostTickets(d4, c4));
    vector<int> d5, c5 = {2, 7, 15};
    for (int i = 1; i <= 30; i++) d5.push_back(i);
    ASSERT_EQ(15, sol.mincostTickets(d5, c5));
    vector<int> d6 = {1, 100, 200}, c6 = {2, 7, 15};
    ASSERT_EQ(6, sol.mincostTickets(d6, c6));
    vector<int> d7 = {1, 2, 3, 4, 5}, c7 = {1, 10, 100};
    ASSERT_EQ(5, sol.mincostTickets(d7, c7));
    vector<int> d8;
    for (int i = 1; i <= 10; i++) d8.push_back(i);
    vector<int> c8 = {5, 5, 5};
    ASSERT_EQ(5, sol.mincostTickets(d8, c8));
    vector<int> d9 = {1, 365}, c9 = {5, 50, 200};
    ASSERT_EQ(10, sol.mincostTickets(d9, c9));
}

TEST(dp, min_cost_tickets2) {
    MinCostTicketsMemo sol;
    vector<int> d1 = {1, 4, 6, 7, 8, 20}, c1 = {2, 7, 15};
    ASSERT_EQ(11, sol.mincostTickets(d1, c1));
    vector<int> d2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, c2 = {2, 7, 15};
    ASSERT_EQ(17, sol.mincostTickets(d2, c2));
    vector<int> d3 = {1}, c3 = {2, 7, 15};
    ASSERT_EQ(2, sol.mincostTickets(d3, c3));
    vector<int> d4 = {1, 2, 3, 4, 5, 6, 7}, c4 = {2, 7, 15};
    ASSERT_EQ(7, sol.mincostTickets(d4, c4));
    vector<int> d5, c5 = {2, 7, 15};
    for (int i = 1; i <= 30; i++) d5.push_back(i);
    ASSERT_EQ(15, sol.mincostTickets(d5, c5));
    vector<int> d6 = {1, 100, 200}, c6 = {2, 7, 15};
    ASSERT_EQ(6, sol.mincostTickets(d6, c6));
    vector<int> d7 = {1, 2, 3, 4, 5}, c7 = {1, 10, 100};
    ASSERT_EQ(5, sol.mincostTickets(d7, c7));
    vector<int> d8;
    for (int i = 1; i <= 10; i++) d8.push_back(i);
    vector<int> c8 = {5, 5, 5};
    ASSERT_EQ(5, sol.mincostTickets(d8, c8));
    vector<int> d9 = {1, 365}, c9 = {5, 50, 200};
    ASSERT_EQ(10, sol.mincostTickets(d9, c9));
}
