#include "gtest/gtest.h"
#include "list/RemoveNthFromEnd.hpp"
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

void verify(const vector<int>& input, int n, const vector<int>& expected) {
    SolutionRemoveNthFromEnd sol;
    {
        ListNode* h = fromVec(input);
        ListNode* r = sol.removeNthFromEnd(h, n);
        ASSERT_EQ(expected, toVec(r));
        freeList(r);
    }
    {
        ListNode* h = fromVec(input);
        ListNode* r = sol.removeNthFromEndCount(h, n);
        ASSERT_EQ(expected, toVec(r));
        freeList(r);
    }
}
}  // namespace

TEST(list, remove_nth_from_end) {
    verify({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5});
    verify({1}, 1, {});
    verify({1, 2}, 1, {1});
    verify({1, 2}, 2, {2});
}
