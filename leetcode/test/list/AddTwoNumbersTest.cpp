#include "gtest/gtest.h"
#include "list/AddTwoNumbers.hpp"
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

}  // namespace

TEST(list, add_two_numbers_basic) {
    SolutionAddTwoNumbers sol;
    ListNode* a = fromVec({2, 4, 3});
    ListNode* b = fromVec({5, 6, 4});
    ListNode* r = sol.addTwoNumbers(a, b);
    ASSERT_EQ((vector<int>{7, 0, 8}), toVec(r));
    freeList(a); freeList(b); freeList(r);
}

TEST(list, add_two_numbers_carry_propagation) {
    SolutionAddTwoNumbers sol;
    ListNode* a = fromVec({9, 9, 9});
    ListNode* b = fromVec({1});
    ListNode* r = sol.addTwoNumbers(a, b);
    ASSERT_EQ((vector<int>{0, 0, 0, 1}), toVec(r));
    freeList(a); freeList(b); freeList(r);
}

TEST(list, add_two_numbers_different_lengths) {
    SolutionAddTwoNumbers sol;
    ListNode* a = fromVec({9, 9});
    ListNode* b = fromVec({1});
    ListNode* r = sol.addTwoNumbers(a, b);
    ASSERT_EQ((vector<int>{0, 0, 1}), toVec(r));
    freeList(a); freeList(b); freeList(r);
}

TEST(list, add_two_numbers_both_zeros) {
    SolutionAddTwoNumbers sol;
    ListNode* a = fromVec({0});
    ListNode* b = fromVec({0});
    ListNode* r = sol.addTwoNumbers(a, b);
    ASSERT_EQ((vector<int>{0}), toVec(r));
    freeList(a); freeList(b); freeList(r);
}

TEST(list, add_two_numbers_single_digit_carry) {
    SolutionAddTwoNumbers sol;
    ListNode* a = fromVec({5});
    ListNode* b = fromVec({5});
    ListNode* r = sol.addTwoNumbers(a, b);
    ASSERT_EQ((vector<int>{0, 1}), toVec(r));
    freeList(a); freeList(b); freeList(r);
}

TEST(list, add_two_numbers_recursive_basic) {
    SolutionAddTwoNumbers sol;
    ListNode* a = fromVec({2, 4, 3});
    ListNode* b = fromVec({5, 6, 4});
    ListNode* r = sol.addTwoNumbersRecursive(a, b);
    ASSERT_EQ((vector<int>{7, 0, 8}), toVec(r));
    freeList(a); freeList(b); freeList(r);
}

TEST(list, add_two_numbers_recursive_carry) {
    SolutionAddTwoNumbers sol;
    ListNode* a = fromVec({9, 9, 9});
    ListNode* b = fromVec({1});
    ListNode* r = sol.addTwoNumbersRecursive(a, b);
    ASSERT_EQ((vector<int>{0, 0, 0, 1}), toVec(r));
    freeList(a); freeList(b); freeList(r);
}
