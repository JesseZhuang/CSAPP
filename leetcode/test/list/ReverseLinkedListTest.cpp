#include "gtest/gtest.h"
#include "list/ReverseLinkedList.hpp"
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

void verify(const vector<int>& input, const vector<int>& expected) {
    SolutionReverseLinkedList sol;
    {
        ListNode* h = fromVec(input);
        ListNode* r = sol.reverseListIterative(h);
        ASSERT_EQ(expected, toVec(r));
        freeList(r);
    }
    {
        ListNode* h = fromVec(input);
        ListNode* r = sol.reverseListRecursive(h);
        ASSERT_EQ(expected, toVec(r));
        freeList(r);
    }
}
}  // namespace

TEST(list, reverse_linked_list_example1) {
    verify({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
}

TEST(list, reverse_linked_list_two_nodes) {
    verify({1, 2}, {2, 1});
}

TEST(list, reverse_linked_list_empty) {
    verify({}, {});
}

TEST(list, reverse_linked_list_single_node) {
    verify({42}, {42});
}

TEST(list, reverse_linked_list_negative_values) {
    verify({-5, 0, 5, -10}, {-10, 5, 0, -5});
}

TEST(list, reverse_linked_list_duplicates) {
    verify({1, 1, 2, 2, 3, 3}, {3, 3, 2, 2, 1, 1});
}

TEST(list, reverse_linked_list_long_list) {
    vector<int> input;
    vector<int> expected;
    for (int i = 1; i <= 100; ++i) input.push_back(i);
    for (int i = 100; i >= 1; --i) expected.push_back(i);
    verify(input, expected);
}
