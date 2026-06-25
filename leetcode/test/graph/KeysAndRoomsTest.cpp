#include "gtest/gtest.h"
#include "graph/KeysAndRooms.hpp"

TEST(graph, keys_and_rooms_example1) {
    Solution841 sol;
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    EXPECT_TRUE(sol.canVisitAllRooms(rooms));
    EXPECT_TRUE(sol.canVisitAllRoomsBFS(rooms));
}

TEST(graph, keys_and_rooms_example2) {
    Solution841 sol;
    vector<vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    EXPECT_FALSE(sol.canVisitAllRooms(rooms));
    EXPECT_FALSE(sol.canVisitAllRoomsBFS(rooms));
}

TEST(graph, keys_and_rooms_single_room) {
    Solution841 sol;
    vector<vector<int>> rooms = {{}};
    EXPECT_TRUE(sol.canVisitAllRooms(rooms));
    EXPECT_TRUE(sol.canVisitAllRoomsBFS(rooms));
}

TEST(graph, keys_and_rooms_all_keys_in_first) {
    Solution841 sol;
    vector<vector<int>> rooms = {{1, 2, 3}, {}, {}, {}};
    EXPECT_TRUE(sol.canVisitAllRooms(rooms));
    EXPECT_TRUE(sol.canVisitAllRoomsBFS(rooms));
}

TEST(graph, keys_and_rooms_chain) {
    Solution841 sol;
    vector<vector<int>> rooms = {{1}, {2}, {3}, {4}, {}};
    EXPECT_TRUE(sol.canVisitAllRooms(rooms));
    EXPECT_TRUE(sol.canVisitAllRoomsBFS(rooms));
}

TEST(graph, keys_and_rooms_isolated) {
    Solution841 sol;
    vector<vector<int>> rooms = {{}, {2}, {1}, {}};
    EXPECT_FALSE(sol.canVisitAllRooms(rooms));
    EXPECT_FALSE(sol.canVisitAllRoomsBFS(rooms));
}

TEST(graph, keys_and_rooms_duplicates) {
    Solution841 sol;
    vector<vector<int>> rooms = {{1, 1, 1, 2}, {2, 2}, {3}, {}};
    EXPECT_TRUE(sol.canVisitAllRooms(rooms));
    EXPECT_TRUE(sol.canVisitAllRoomsBFS(rooms));
}

TEST(graph, keys_and_rooms_cycle) {
    Solution841 sol;
    // Cycle between 0 and 1, but room 2 is unreachable
    vector<vector<int>> rooms = {{1}, {0}, {}};
    EXPECT_FALSE(sol.canVisitAllRooms(rooms));
    EXPECT_FALSE(sol.canVisitAllRoomsBFS(rooms));
}
