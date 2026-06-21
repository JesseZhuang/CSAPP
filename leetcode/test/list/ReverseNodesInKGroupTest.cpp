#include "gtest/gtest.h"
#include "list/ReverseNodesInKGroup.hpp"
#include "struct/ListNode.hpp"

#include <vector>

using namespace std;

namespace {
ListNode* fromVec(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}
vector<int> toVec(ListNode* head) {
    vector<int> out;
    while (head) { out.push_back(head->val); head = head->next; }
    return out;
}
void freeList(ListNode* head) {
    while (head) { ListNode* nx = head->next; delete head; head = nx; }
}

void verify(const vector<int>& input, int k, const vector<int>& expected) {
    // Iterative
    {
        SolutionReverseNodesInKGroup1 sol;
        ListNode* h = fromVec(input);
        ListNode* r = sol.reverseKGroup(h, k);
        ASSERT_EQ(expected, toVec(r));
        freeList(r);
    }
    // Recursive
    {
        SolutionReverseNodesInKGroup2 sol;
        ListNode* h = fromVec(input);
        ListNode* r = sol.reverseKGroup(h, k);
        ASSERT_EQ(expected, toVec(r));
        freeList(r);
    }
}
}  // namespace

TEST(list, reverse_nodes_in_k_group_k2) {
    verify({1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5});
}

TEST(list, reverse_nodes_in_k_group_k3) {
    verify({1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5});
}

TEST(list, reverse_nodes_in_k_group_k1) {
    verify({1, 2, 3, 4, 5}, 1, {1, 2, 3, 4, 5});
}

TEST(list, reverse_nodes_in_k_group_k_equals_length) {
    verify({1, 2, 3, 4, 5}, 5, {5, 4, 3, 2, 1});
}

TEST(list, reverse_nodes_in_k_group_single_node) {
    verify({1}, 1, {1});
}

TEST(list, reverse_nodes_in_k_group_k_greater_than_length) {
    verify({1, 2, 3}, 5, {1, 2, 3});
}

TEST(list, reverse_nodes_in_k_group_null) {
    verify({}, 2, {});
}

TEST(list, reverse_nodes_in_k_group_two_full_groups) {
    verify({1, 2, 3, 4}, 2, {2, 1, 4, 3});
}
