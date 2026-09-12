#include "gtest/gtest.h"
#include "list/PalindromeLL.hpp"
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

void verify(const vector<int>& input, bool expected) {
    SolutionPalindromeLL sol;
    {
        ListNode* h = fromVec(input);
        ASSERT_EQ(expected, sol.isPalindrome(h));
        freeList(h);
    }
    {
        ListNode* h = fromVec(input);
        ASSERT_EQ(expected, sol.isPalindromeStack(h));
        freeList(h);
    }
}
}  // namespace

TEST(list, palindrome_ll_even) {
    verify({1, 2, 2, 1}, true);
}

TEST(list, palindrome_ll_not) {
    verify({1, 2}, false);
}

TEST(list, palindrome_ll_single) {
    verify({1}, true);
}

TEST(list, palindrome_ll_odd) {
    verify({1, 2, 1}, true);
}

TEST(list, palindrome_ll_odd_not) {
    verify({1, 2, 3}, false);
}

TEST(list, palindrome_ll_all_same) {
    verify({5, 5, 5, 5}, true);
}

TEST(list, palindrome_ll_two_same) {
    verify({1, 1}, true);
}

TEST(list, palindrome_ll_boundary) {
    verify({0, 9, 0}, true);
    verify({0, 9, 1}, false);
}
