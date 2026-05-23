#include "gtest/gtest.h"
#include "heap/TaskScheduler.hpp"

TEST(heap, task_scheduler) {
    Solution621 sol;

    vector<char> t1 = {'A','A','A','B','B','B'};
    ASSERT_EQ(8, sol.leastInterval(t1, 2));

    vector<char> t2 = {'A','C','A','B','D','B'};
    ASSERT_EQ(6, sol.leastInterval(t2, 1));

    vector<char> t3 = {'A','A','A','B','B','B'};
    ASSERT_EQ(10, sol.leastInterval(t3, 3));

    vector<char> t4 = {'A','B','C'};
    ASSERT_EQ(3, sol.leastInterval(t4, 0));

    vector<char> t5 = {'A'};
    ASSERT_EQ(1, sol.leastInterval(t5, 2));

    vector<char> t6 = {'A','A','A'};
    ASSERT_EQ(7, sol.leastInterval(t6, 2));

    vector<char> t7 = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                       'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    ASSERT_EQ(26, sol.leastInterval(t7, 100));

    vector<char> t8 = {'A','A','B'};
    ASSERT_EQ(5, sol.leastInterval(t8, 3));
}
