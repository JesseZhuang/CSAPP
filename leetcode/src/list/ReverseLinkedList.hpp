#ifndef REVERSE_LINKED_LIST_HPP
#define REVERSE_LINKED_LIST_HPP

#include "struct/ListNode.hpp"

using namespace std;

/// LeetCode 206 / LintCode 35, easy, tags: linked list, recursion.
class SolutionReverseLinkedList {
public:
    /// Iterative. Time O(n), Space O(1).
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* res = nullptr;
        while (head) {
            ListNode* next = head->next;   // save successor
            head->next = res;              // reverse the link
            res = head;                    // advance res
            head = next;                   // advance head
        }
        return res;
    }

    /// Recursive. Time O(n), Space O(n) recursion stack.
    ListNode* reverseListRecursive(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* rev = reverseListRecursive(head->next);  // reverse rest
        head->next->next = head;                            // make next point back
        head->next = nullptr;                               // break old forward link
        return rev;
    }
};

#endif
