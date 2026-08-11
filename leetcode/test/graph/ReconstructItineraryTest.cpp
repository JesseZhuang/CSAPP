#include "gtest/gtest.h"
#include "graph/ReconstructItinerary.hpp"

TEST(graph, reconstruct_itinerary) {
    vector<vector<string>> t1 = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    EXPECT_EQ(Solution332::findItinerary(t1),
              vector<string>({"JFK","MUC","LHR","SFO","SJC"}));

    vector<vector<string>> t2 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    EXPECT_EQ(Solution332::findItinerary(t2),
              vector<string>({"JFK","ATL","JFK","SFO","ATL","SFO"}));

    vector<vector<string>> t3 = {{"JFK","A"}};
    EXPECT_EQ(Solution332::findItinerary(t3),
              vector<string>({"JFK","A"}));

    vector<vector<string>> t4 = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    EXPECT_EQ(Solution332::findItinerary(t4),
              vector<string>({"JFK","NRT","JFK","KUL"}));

    vector<vector<string>> t5 = {{"JFK","A"},{"A","JFK"},{"JFK","A"}};
    EXPECT_EQ(Solution332::findItinerary(t5),
              vector<string>({"JFK","A","JFK","A"}));
}

TEST(graph, reconstruct_itinerary_iterative) {
    vector<vector<string>> t1 = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    EXPECT_EQ(Solution332::findItinerary2(t1),
              vector<string>({"JFK","MUC","LHR","SFO","SJC"}));

    vector<vector<string>> t2 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    EXPECT_EQ(Solution332::findItinerary2(t2),
              vector<string>({"JFK","ATL","JFK","SFO","ATL","SFO"}));

    vector<vector<string>> t3 = {{"JFK","A"}};
    EXPECT_EQ(Solution332::findItinerary2(t3),
              vector<string>({"JFK","A"}));

    vector<vector<string>> t4 = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    EXPECT_EQ(Solution332::findItinerary2(t4),
              vector<string>({"JFK","NRT","JFK","KUL"}));

    vector<vector<string>> t5 = {{"JFK","A"},{"A","JFK"},{"JFK","A"}};
    EXPECT_EQ(Solution332::findItinerary2(t5),
              vector<string>({"JFK","A","JFK","A"}));
}
