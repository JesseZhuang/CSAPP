#include "gtest/gtest.h"
#include "list/MergeKSortedLists.hpp"
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

void verify(const vector<vector<int>>& input, const vector<int>& expected) {
    SolutionMergeKSortedLists sol;
    {
        vector<ListNode*> lists;
        for (const auto& v : input) lists.push_back(fromVec(v));
        ListNode* m = sol.mergeKListsHeap(lists);
        ASSERT_EQ(expected, toVec(m));
        freeList(m);
    }
    {
        vector<ListNode*> lists;
        for (const auto& v : input) lists.push_back(fromVec(v));
        ListNode* m = sol.mergeKListsDivideConquer(lists);
        ASSERT_EQ(expected, toVec(m));
        freeList(m);
    }
}

}  // namespace

TEST(list, merge_k_sorted_lists_example1) {
    verify({{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6});
}

TEST(list, merge_k_sorted_lists_no_lists) {
    SolutionMergeKSortedLists sol;
    vector<ListNode*> lists;
    ASSERT_EQ(nullptr, sol.mergeKListsHeap(lists));
    ASSERT_EQ(nullptr, sol.mergeKListsDivideConquer(lists));
}

TEST(list, merge_k_sorted_lists_all_empty) {
    SolutionMergeKSortedLists sol;
    vector<ListNode*> lists{nullptr, nullptr};
    ASSERT_EQ(nullptr, sol.mergeKListsHeap(lists));
    ASSERT_EQ(nullptr, sol.mergeKListsDivideConquer(lists));
}

TEST(list, merge_k_sorted_lists_single_list) {
    verify({{1, 2, 3}}, {1, 2, 3});
}

TEST(list, merge_k_sorted_lists_with_empty_in_middle) {
    verify({{1, 3, 5}, {}, {2, 4, 6}}, {1, 2, 3, 4, 5, 6});
}

TEST(list, merge_k_sorted_lists_negative_values) {
    verify({{-5, 0, 5}, {-3, 3}, {-1, 1}}, {-5, -3, -1, 0, 1, 3, 5});
}

TEST(list, merge_k_sorted_lists_one_long_others_single) {
    verify({{1, 2, 3, 4, 5}, {6}, {7}}, {1, 2, 3, 4, 5, 6, 7});
}

TEST(list, merge_k_sorted_lists_duplicates_across_lists) {
    verify({{2, 2, 2}, {2, 2}, {2}}, {2, 2, 2, 2, 2, 2});
}

TEST(list, merge_k_sorted_lists_many_singletons) {
    verify({{5}, {1}, {3}, {2}, {4}}, {1, 2, 3, 4, 5});
}
