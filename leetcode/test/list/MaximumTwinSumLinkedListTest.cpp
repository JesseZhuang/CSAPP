#include "gtest/gtest.h"
#include "list/MaximumTwinSumLinkedList.hpp"
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

void freeList(ListNode* head) {
    while (head) { ListNode* nx = head->next; delete head; head = nx; }
}

void verify(const vector<int>& input, int expected) {
    SolutionMaximumTwinSumLinkedList sol;

    // Test reverse approach
    ListNode* h1 = fromVec(input);
    ASSERT_EQ(expected, sol.pairSum(h1));
    // pairSum mutates the list, free what we can (head half is intact)
    // but the list is split; just leak-safe free both halves is tricky,
    // so we skip free for the reverse approach's mutated list.

    // Test stack approach (non-mutating)
    ListNode* h2 = fromVec(input);
    ASSERT_EQ(expected, sol.pairSumStack(h2));
    freeList(h2);
}

}  // namespace

TEST(list, maximum_twin_sum_basic) {
    verify({5, 4, 2, 1}, 6);
}

TEST(list, maximum_twin_sum_unequal_halves) {
    verify({4, 2, 2, 3}, 7);
}

TEST(list, maximum_twin_sum_two_nodes) {
    verify({1, 100000}, 100001);
}

TEST(list, maximum_twin_sum_min_pair) {
    verify({1, 1}, 2);
}

TEST(list, maximum_twin_sum_all_equal) {
    verify({5, 5, 5, 5}, 10);
}

TEST(list, maximum_twin_sum_symmetric) {
    verify({100, 1, 1, 100}, 200);
}

TEST(list, maximum_twin_sum_six_nodes) {
    verify({1, 2, 3, 4, 5, 6}, 7);
}
