#include "gtest/gtest.h"
#include "graph/NetworkDelayTime.hpp"

using namespace std;

TEST(graph, network_delay_time) {
    Solution743 sol;

    // Test 1
    vector<vector<int>> times1{{2,1,1},{2,3,1},{3,4,1}};
    ASSERT_EQ(2, sol.networkDelayTime(times1, 4, 2));

    // Test 2
    vector<vector<int>> times2{{1,2,1}};
    ASSERT_EQ(1, sol.networkDelayTime(times2, 2, 1));

    // Test 3: unreachable node
    vector<vector<int>> times3{{1,2,1}};
    ASSERT_EQ(-1, sol.networkDelayTime(times3, 2, 2));

    // Test 4: multiple paths
    vector<vector<int>> times4{{1,2,1},{1,3,4},{2,3,2}};
    ASSERT_EQ(3, sol.networkDelayTime(times4, 3, 1));

    // Test 5: disconnected graph
    vector<vector<int>> times5{{1,2,1},{3,2,1}};
    ASSERT_EQ(-1, sol.networkDelayTime(times5, 3, 1));
}
