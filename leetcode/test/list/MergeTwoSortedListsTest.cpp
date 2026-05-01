#include "gtest/gtest.h"
#include "list/MergeTwoSortedLists.hpp"
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

TEST(list, merge_two_sorted_lists_example1) {
    SolutionMergeTwoSortedLists sol;
    ListNode* a = fromVec({1, 2, 4});
    ListNode* b = fromVec({1, 3, 4});
    ListNode* m = sol.mergeTwoLists(a, b);
    ASSERT_EQ((vector<int>{1, 1, 2, 3, 4, 4}), toVec(m));
    freeList(m);
}

TEST(list, merge_two_sorted_lists_both_empty) {
    SolutionMergeTwoSortedLists sol;
    ASSERT_EQ(nullptr, sol.mergeTwoLists(nullptr, nullptr));
}

TEST(list, merge_two_sorted_lists_one_empty) {
    SolutionMergeTwoSortedLists sol;
    ListNode* b = fromVec({0});
    ListNode* m = sol.mergeTwoLists(nullptr, b);
    ASSERT_EQ((vector<int>{0}), toVec(m));
    freeList(m);
}

TEST(list, merge_two_sorted_lists_left_smaller_all) {
    SolutionMergeTwoSortedLists sol;
    ListNode* a = fromVec({1, 2, 3});
    ListNode* b = fromVec({4, 5, 6});
    ListNode* m = sol.mergeTwoLists(a, b);
    ASSERT_EQ((vector<int>{1, 2, 3, 4, 5, 6}), toVec(m));
    freeList(m);
}

TEST(list, merge_two_sorted_lists_interleaved) {
    SolutionMergeTwoSortedLists sol;
    ListNode* a = fromVec({-5, 0, 7});
    ListNode* b = fromVec({-3, 4, 8});
    ListNode* m = sol.mergeTwoLists(a, b);
    ASSERT_EQ((vector<int>{-5, -3, 0, 4, 7, 8}), toVec(m));
    freeList(m);
}

TEST(list, merge_two_sorted_lists_duplicates_across) {
    SolutionMergeTwoSortedLists sol;
    ListNode* a = fromVec({1, 1, 1});
    ListNode* b = fromVec({1, 1});
    ListNode* m = sol.mergeTwoLists(a, b);
    ASSERT_EQ((vector<int>{1, 1, 1, 1, 1}), toVec(m));
    freeList(m);
}

TEST(list, merge_two_sorted_lists_one_long_one_short) {
    SolutionMergeTwoSortedLists sol;
    ListNode* a = fromVec({1});
    ListNode* b = fromVec({2, 3, 4, 5, 6});
    ListNode* m = sol.mergeTwoLists(a, b);
    ASSERT_EQ((vector<int>{1, 2, 3, 4, 5, 6}), toVec(m));
    freeList(m);
}
