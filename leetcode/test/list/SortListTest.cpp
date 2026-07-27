#include "gtest/gtest.h"
#include "list/SortList.hpp"
#include "struct/ListNode.hpp"

#include <vector>

using namespace std;

namespace {

ListNode* build(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : vals) { tail->next = new ListNode(x); tail = tail->next; }
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

// --- Bottom-up iterative merge sort tests ---

TEST(list, sort_list) {
    SolutionSortList sol;

    // [4,2,1,3] -> [1,2,3,4]
    ListNode* h = sol.sortList(build({4, 2, 1, 3}));
    ASSERT_EQ((vector<int>{1, 2, 3, 4}), toVec(h));
    freeList(h);

    // [-1,5,3,4,0] -> [-1,0,3,4,5]
    h = sol.sortList(build({-1, 5, 3, 4, 0}));
    ASSERT_EQ((vector<int>{-1, 0, 3, 4, 5}), toVec(h));
    freeList(h);

    // empty
    ASSERT_EQ(nullptr, sol.sortList(nullptr));

    // single node
    h = sol.sortList(build({42}));
    ASSERT_EQ((vector<int>{42}), toVec(h));
    freeList(h);

    // duplicates [3,1,2,3,1] -> [1,1,2,3,3]
    h = sol.sortList(build({3, 1, 2, 3, 1}));
    ASSERT_EQ((vector<int>{1, 1, 2, 3, 3}), toVec(h));
    freeList(h);

    // reverse sorted [5,4,3,2,1] -> [1,2,3,4,5]
    h = sol.sortList(build({5, 4, 3, 2, 1}));
    ASSERT_EQ((vector<int>{1, 2, 3, 4, 5}), toVec(h));
    freeList(h);
}

// --- Top-down recursive merge sort tests ---

TEST(list, sort_list_recursive) {
    SolutionSortList sol;

    // [4,2,1,3] -> [1,2,3,4]
    ListNode* h = sol.sortListRecursive(build({4, 2, 1, 3}));
    ASSERT_EQ((vector<int>{1, 2, 3, 4}), toVec(h));
    freeList(h);

    // [-1,5,3,4,0] -> [-1,0,3,4,5]
    h = sol.sortListRecursive(build({-1, 5, 3, 4, 0}));
    ASSERT_EQ((vector<int>{-1, 0, 3, 4, 5}), toVec(h));
    freeList(h);

    // empty
    ASSERT_EQ(nullptr, sol.sortListRecursive(nullptr));

    // single node
    h = sol.sortListRecursive(build({42}));
    ASSERT_EQ((vector<int>{42}), toVec(h));
    freeList(h);

    // duplicates [3,1,2,3,1] -> [1,1,2,3,3]
    h = sol.sortListRecursive(build({3, 1, 2, 3, 1}));
    ASSERT_EQ((vector<int>{1, 1, 2, 3, 3}), toVec(h));
    freeList(h);

    // reverse sorted [5,4,3,2,1] -> [1,2,3,4,5]
    h = sol.sortListRecursive(build({5, 4, 3, 2, 1}));
    ASSERT_EQ((vector<int>{1, 2, 3, 4, 5}), toVec(h));
    freeList(h);
}
