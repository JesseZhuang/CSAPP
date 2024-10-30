#include "gtest/gtest.h"
#include "heap/MeetingRoomsIII.hpp"

using namespace std;

TEST(heap, meeting_rooms_3) {
    vector<vector<int>> meetings({
                                         {0, 10},
                                         {1, 5},
                                         {2, 7},
                                         {3, 4}
                                 }); // both room 0 and 1 hold 2 meetings
    Solution tbt;
    int exp = tbt.mostBooked(2, meetings);
    cout << exp << endl;
    ASSERT_EQ(0, exp);
}
