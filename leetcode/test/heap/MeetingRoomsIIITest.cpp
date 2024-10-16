#include "gtest/gtest.h"
#include "heap/MeetingRoomsIII.hpp"

using namespace std;

TEST(heap, meeting_rooms_3) {
    vector<vector<int>> meetings({
                                         {0, 10},
                                         {1, 5},
                                         {2, 7},
                                         {3, 4}
                                 });
    Solution tbt;
    cout << tbt.mostBooked(0, meetings);
}
