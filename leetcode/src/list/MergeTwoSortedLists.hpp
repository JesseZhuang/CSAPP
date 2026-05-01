#ifndef MERGE_TWO_SORTED_LISTS_HPP
#define MERGE_TWO_SORTED_LISTS_HPP

#include "struct/ListNode.hpp"

using namespace std;

/// LeetCode 21 / LintCode 165, easy, tags: linked list, recursion.
class SolutionMergeTwoSortedLists {
public:
    /// Iterative splice. Time O(n + m), Space O(1).
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) { cur->next = l1; l1 = l1->next; }
            else                   { cur->next = l2; l2 = l2->next; }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

#endif
