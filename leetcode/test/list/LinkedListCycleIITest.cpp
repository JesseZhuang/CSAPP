#include "gtest/gtest.h"
#include "list/LinkedListCycleII.hpp"
#include "struct/ListNode.hpp"
#include <vector>

using namespace std;

namespace {

// Build list with cycle at pos (-1 for no cycle). Returns {head, expected_cycle_node}.
pair<ListNode*, ListNode*> buildCycleList(const vector<int>& vals, int pos) {
    if (vals.empty()) return {nullptr, nullptr};
    vector<ListNode*> nodes;
    for (int v : vals) nodes.push_back(new ListNode(v));
    for (int i = 0; i < (int)nodes.size() - 1; i++) nodes[i]->next = nodes[i+1];
    ListNode* expected = nullptr;
    if (pos >= 0) {
        nodes.back()->next = nodes[pos];
        expected = nodes[pos];
    }
    return {nodes[0], expected};
}

}  // namespace

TEST(list, linked_list_cycle_ii_example1) {
    SolutionLinkedListCycleII sol;
    auto [head, expected] = buildCycleList({3,2,0,-4}, 1);
    ASSERT_EQ(sol.detectCycle(head), expected);
    ASSERT_EQ(sol.detectCycleHash(head), expected);
}

TEST(list, linked_list_cycle_ii_example2) {
    SolutionLinkedListCycleII sol;
    auto [head, expected] = buildCycleList({1,2}, 0);
    ASSERT_EQ(sol.detectCycle(head), expected);
    ASSERT_EQ(sol.detectCycleHash(head), expected);
}

TEST(list, linked_list_cycle_ii_no_cycle) {
    SolutionLinkedListCycleII sol;
    auto [head, expected] = buildCycleList({1}, -1);
    ASSERT_EQ(sol.detectCycle(head), nullptr);
    ASSERT_EQ(sol.detectCycleHash(head), nullptr);
}

TEST(list, linked_list_cycle_ii_null) {
    SolutionLinkedListCycleII sol;
    ASSERT_EQ(sol.detectCycle(nullptr), nullptr);
    ASSERT_EQ(sol.detectCycleHash(nullptr), nullptr);
}

TEST(list, linked_list_cycle_ii_self_cycle) {
    SolutionLinkedListCycleII sol;
    auto [head, expected] = buildCycleList({1}, 0);
    ASSERT_EQ(sol.detectCycle(head), expected);
    ASSERT_EQ(sol.detectCycleHash(head), expected);
}

TEST(list, linked_list_cycle_ii_long_tail) {
    SolutionLinkedListCycleII sol;
    auto [head, expected] = buildCycleList({1,2,3,4,5}, 3);
    ASSERT_EQ(sol.detectCycle(head), expected);
    ASSERT_EQ(sol.detectCycleHash(head), expected);
}

TEST(list, linked_list_cycle_ii_tail_self_loop) {
    SolutionLinkedListCycleII sol;
    auto [head, expected] = buildCycleList({1,2,3}, 2);
    ASSERT_EQ(sol.detectCycle(head), expected);
    ASSERT_EQ(sol.detectCycleHash(head), expected);
}
