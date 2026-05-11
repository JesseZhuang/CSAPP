#include "gtest/gtest.h"
#include "list/ReorderList.hpp"
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
    SolutionReorderList sol;
    {
        ListNode* h = fromVec(input);
        sol.reorderList(h);
        ASSERT_EQ(expected, toVec(h));
        freeList(h);
    }
    {
        ListNode* h = fromVec(input);
        sol.reorderListStack(h);
        ASSERT_EQ(expected, toVec(h));
        freeList(h);
    }
}
}  // namespace

TEST(list, reorder_list_even) {
    verify({1, 2, 3, 4}, {1, 4, 2, 3});
}

TEST(list, reorder_list_odd) {
    verify({1, 2, 3, 4, 5}, {1, 5, 2, 4, 3});
}

TEST(list, reorder_list_single) {
    verify({1}, {1});
}

TEST(list, reorder_list_two) {
    verify({1, 2}, {1, 2});
}

TEST(list, reorder_list_three) {
    verify({1, 2, 3}, {1, 3, 2});
}

TEST(list, reorder_list_six) {
    verify({1, 2, 3, 4, 5, 6}, {1, 6, 2, 5, 3, 4});
}
