#include "gtest/gtest.h"
#include "graph/CourseScheduleII.hpp"

#include <unordered_map>

using namespace std;

static bool isValidOrder(const vector<int> &order, int n, const vector<vector<int>> &prereqs) {
    if ((int) order.size() != n) return false;
    unordered_map<int, int> pos;
    for (int i = 0; i < (int) order.size(); i++) pos[order[i]] = i;
    if ((int) pos.size() != n) return false;
    for (auto &e: prereqs)
        if (pos[e[1]] >= pos[e[0]]) return false;
    return true;
}

TEST(graph, course_schedule_ii_example1) {
    Solution sol;
    vector<vector<int>> pre{{1, 0}};
    auto res = sol.findOrder(2, pre);
    ASSERT_TRUE(isValidOrder(res, 2, pre));
}

TEST(graph, course_schedule_ii_example2) {
    Solution sol;
    vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    auto res = sol.findOrder(4, pre);
    ASSERT_TRUE(isValidOrder(res, 4, pre));
}

TEST(graph, course_schedule_ii_cycle) {
    Solution sol;
    vector<vector<int>> pre{{1, 0}, {0, 1}};
    auto res = sol.findOrder(2, pre);
    ASSERT_TRUE(res.empty());
}

TEST(graph, course_schedule_ii_no_prereqs) {
    Solution sol;
    vector<vector<int>> pre;
    auto res = sol.findOrder(3, pre);
    ASSERT_TRUE(isValidOrder(res, 3, pre));
}

TEST(graph, course_schedule_ii_single) {
    Solution sol;
    vector<vector<int>> pre;
    auto res = sol.findOrder(1, pre);
    ASSERT_TRUE(isValidOrder(res, 1, pre));
}

TEST(graph, course_schedule_ii_chain) {
    Solution sol;
    vector<vector<int>> pre{{1, 0}, {2, 1}, {3, 2}};
    auto res = sol.findOrder(4, pre);
    ASSERT_TRUE(isValidOrder(res, 4, pre));
}

TEST(graph, course_schedule_ii_cycle_in_chain) {
    Solution sol;
    vector<vector<int>> pre{{1, 0}, {2, 1}, {3, 2}, {0, 3}};
    auto res = sol.findOrder(4, pre);
    ASSERT_TRUE(res.empty());
}

TEST(graph, course_schedule_ii_diamond) {
    Solution sol;
    vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    auto res = sol.findOrder(4, pre);
    ASSERT_TRUE(isValidOrder(res, 4, pre));
}
