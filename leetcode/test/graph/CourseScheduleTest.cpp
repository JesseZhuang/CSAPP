#include "gtest/gtest.h"
#include "graph/CourseSchedule.hpp"

using namespace std;

// --- DFS tests ---

TEST(graph, course_schedule_dfs_example1) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}};
    ASSERT_TRUE(sol.canFinishDFS(2, pre));
}

TEST(graph, course_schedule_dfs_example2) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {0, 1}};
    ASSERT_FALSE(sol.canFinishDFS(2, pre));
}

TEST(graph, course_schedule_dfs_no_prereqs) {
    Solution207 sol;
    vector<vector<int>> pre;
    ASSERT_TRUE(sol.canFinishDFS(5, pre));
}

TEST(graph, course_schedule_dfs_single_course) {
    Solution207 sol;
    vector<vector<int>> pre;
    ASSERT_TRUE(sol.canFinishDFS(1, pre));
}

TEST(graph, course_schedule_dfs_chain) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {2, 1}, {3, 2}};
    ASSERT_TRUE(sol.canFinishDFS(4, pre));
}

TEST(graph, course_schedule_dfs_cycle_in_chain) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {2, 1}, {0, 2}};
    ASSERT_FALSE(sol.canFinishDFS(3, pre));
}

TEST(graph, course_schedule_dfs_disconnected) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {3, 2}};
    ASSERT_TRUE(sol.canFinishDFS(4, pre));
}

TEST(graph, course_schedule_dfs_diamond_dag) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    ASSERT_TRUE(sol.canFinishDFS(4, pre));
}

TEST(graph, course_schedule_dfs_self_loop) {
    Solution207 sol;
    vector<vector<int>> pre{{0, 0}};
    ASSERT_FALSE(sol.canFinishDFS(1, pre));
}

TEST(graph, course_schedule_dfs_all_depend_on_one) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 0}, {4, 0}};
    ASSERT_TRUE(sol.canFinishDFS(5, pre));
}

TEST(graph, course_schedule_dfs_multi_component_one_cycle) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {3, 2}, {2, 3}};
    ASSERT_FALSE(sol.canFinishDFS(4, pre));
}

// --- BFS tests ---

TEST(graph, course_schedule_bfs_example1) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}};
    ASSERT_TRUE(sol.canFinishBFS(2, pre));
}

TEST(graph, course_schedule_bfs_example2) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {0, 1}};
    ASSERT_FALSE(sol.canFinishBFS(2, pre));
}

TEST(graph, course_schedule_bfs_no_prereqs) {
    Solution207 sol;
    vector<vector<int>> pre;
    ASSERT_TRUE(sol.canFinishBFS(5, pre));
}

TEST(graph, course_schedule_bfs_single_course) {
    Solution207 sol;
    vector<vector<int>> pre;
    ASSERT_TRUE(sol.canFinishBFS(1, pre));
}

TEST(graph, course_schedule_bfs_chain) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {2, 1}, {3, 2}};
    ASSERT_TRUE(sol.canFinishBFS(4, pre));
}

TEST(graph, course_schedule_bfs_cycle_in_chain) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {2, 1}, {0, 2}};
    ASSERT_FALSE(sol.canFinishBFS(3, pre));
}

TEST(graph, course_schedule_bfs_disconnected) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {3, 2}};
    ASSERT_TRUE(sol.canFinishBFS(4, pre));
}

TEST(graph, course_schedule_bfs_diamond_dag) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    ASSERT_TRUE(sol.canFinishBFS(4, pre));
}

TEST(graph, course_schedule_bfs_self_loop) {
    Solution207 sol;
    vector<vector<int>> pre{{0, 0}};
    ASSERT_FALSE(sol.canFinishBFS(1, pre));
}

TEST(graph, course_schedule_bfs_all_depend_on_one) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 0}, {4, 0}};
    ASSERT_TRUE(sol.canFinishBFS(5, pre));
}

TEST(graph, course_schedule_bfs_multi_component_one_cycle) {
    Solution207 sol;
    vector<vector<int>> pre{{1, 0}, {3, 2}, {2, 3}};
    ASSERT_FALSE(sol.canFinishBFS(4, pre));
}
