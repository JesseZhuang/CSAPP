#include "gtest/gtest.h"
#include "heap/MeetingRoomsII.hpp"

TEST(heap, meeting_rooms_ii_heap_example1) {
    MeetingRoomsII sol;
    vector<vector<int>> intervals = {{0,  30}, {5,  10}, {15, 20}};
    EXPECT_EQ(2, sol.minMeetingRoomsHeap(intervals));
}

TEST(heap, meeting_rooms_ii_heap_example2) {
    MeetingRoomsII sol;
    vector<vector<int>> intervals = {{7, 10}, {2, 4}};
    EXPECT_EQ(1, sol.minMeetingRoomsHeap(intervals));
}

TEST(heap, meeting_rooms_ii_sweep_all_overlap) {
    MeetingRoomsII sol;
    vector<vector<int>> intervals = {{1, 10}, {2, 7}, {3, 19}};
    EXPECT_EQ(3, sol.minMeetingRoomsSweep(intervals));
}

TEST(heap, meeting_rooms_ii_heap_back_to_back) {
    MeetingRoomsII sol;
    vector<vector<int>> intervals = {{1, 5}, {5, 10}, {10, 15}};
    EXPECT_EQ(1, sol.minMeetingRoomsHeap(intervals));
}

TEST(heap, meeting_rooms_ii_sweep_all_same) {
    MeetingRoomsII sol;
    vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}, {1, 2}};
    EXPECT_EQ(4, sol.minMeetingRoomsSweep(intervals));
}

TEST(heap, meeting_rooms_ii_heap_single) {
    MeetingRoomsII sol;
    vector<vector<int>> intervals = {{1, 5}};
    EXPECT_EQ(1, sol.minMeetingRoomsHeap(intervals));
}
