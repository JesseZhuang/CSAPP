#include "gtest/gtest.h"
#include "graph/CheapestFlightsWithinKStops.hpp"

using namespace std;

TEST(graph, cheapest_flights_within_k_stops_bf) {
    Solution787BF sol;

    vector<vector<int>> f1{{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    ASSERT_EQ(700, sol.findCheapestPrice(4, f1, 0, 3, 1));

    vector<vector<int>> f2{{0,1,100},{1,2,100},{0,2,500}};
    ASSERT_EQ(200, sol.findCheapestPrice(3, f2, 0, 2, 1));

    vector<vector<int>> f3{{0,1,100},{1,2,100},{0,2,500}};
    ASSERT_EQ(500, sol.findCheapestPrice(3, f3, 0, 2, 0));

    vector<vector<int>> f4{{0,1,100}};
    ASSERT_EQ(-1, sol.findCheapestPrice(3, f4, 0, 2, 1));

    vector<vector<int>> f5{{0,1,50}};
    ASSERT_EQ(50, sol.findCheapestPrice(2, f5, 0, 1, 0));
}

TEST(graph, cheapest_flights_within_k_stops_bfs) {
    Solution787BFS sol;

    vector<vector<int>> f1{{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    ASSERT_EQ(700, sol.findCheapestPrice(4, f1, 0, 3, 1));

    vector<vector<int>> f2{{0,1,100},{1,2,100},{0,2,500}};
    ASSERT_EQ(200, sol.findCheapestPrice(3, f2, 0, 2, 1));

    vector<vector<int>> f3{{0,1,100},{1,2,100},{0,2,500}};
    ASSERT_EQ(500, sol.findCheapestPrice(3, f3, 0, 2, 0));

    vector<vector<int>> f4{{0,1,100}};
    ASSERT_EQ(-1, sol.findCheapestPrice(3, f4, 0, 2, 1));

    vector<vector<int>> f5{{0,1,50}};
    ASSERT_EQ(50, sol.findCheapestPrice(2, f5, 0, 1, 0));
}
