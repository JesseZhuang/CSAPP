#include "gtest/gtest.h"
#include "string/ShortestWayFormString.hpp"

using namespace std;

TEST(string, shortest_way_form_string) {
    SolutionShortestWay sol;
    ASSERT_EQ(2, sol.shortestWay("abc", "abcbc"));
    ASSERT_EQ(-1, sol.shortestWay("abc", "acdbc"));
    ASSERT_EQ(3, sol.shortestWay("xyz", "xzyxz"));
}
