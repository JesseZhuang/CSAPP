#ifndef REVERSE_NODES_IN_K_GROUP_HPP
#define REVERSE_NODES_IN_K_GROUP_HPP

#include "struct/ListNode.hpp"

using namespace std;

/// LeetCode 25, hard, tags: linked list, recursion.

/// Iterative. Time O(n), Space O(1).
class SolutionReverseNodesInKGroup1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            // Check if there are k nodes remaining
            ListNode* kth = groupPrev;
            for (int i = 0; i < k; ++i) {
                kth = kth->next;
                if (!kth) return dummy.next;
            }
            ListNode* groupNext = kth->next;

            // Reverse k nodes: prev, curr within [groupPrev->next, kth]
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            for (int i = 0; i < k; ++i) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            // Connect with previous part
            ListNode* newGroupTail = groupPrev->next; // was first, now last in group
            groupPrev->next = kth; // kth is now the first in the reversed group (== prev after loop? no, prev == kth)
            // Actually after reversal, prev points to the new head of the group which is kth
            groupPrev->next = prev;
            groupPrev = newGroupTail;
        }
    }
};

/// Recursive. Time O(n), Space O(n/k) recursion stack.
class SolutionReverseNodesInKGroup2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are k nodes
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr) return head;
            curr = curr->next;
        }

        // Reverse first k nodes
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // head is now tail of the reversed group; connect to recursively processed rest
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};

#endif
