#ifndef LEET_CODE_SORTLIST_HPP
#define LEET_CODE_SORTLIST_HPP

#include "struct/ListNode.hpp"

// LeetCode 148 - Sort List
// Sort a linked list in O(n log n) time.

class SolutionSortList {
public:
    // Bottom-up iterative merge sort: O(n log n) time, O(1) space.
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Count list length: O(n)
        int len = 0;
        for (ListNode* p = head; p; p = p->next) ++len;

        ListNode dummy(0);
        dummy.next = head;

        // Double the merge width each pass: O(log n) passes
        for (int size = 1; size < len; size <<= 1) {
            ListNode* prev = &dummy;
            ListNode* cur = dummy.next;

            // Merge pairs of sublists of length `size`: O(n) per pass
            while (cur) {
                // Split off left sublist of length `size`
                ListNode* left = cur;
                ListNode* right = split(left, size);
                // Split off right sublist of length `size`
                cur = split(right, size);
                // Merge left and right, append to prev
                prev = merge(left, right, prev);
            }
        }
        return dummy.next;
    }

    // Top-down recursive merge sort: O(n log n) time, O(log n) stack space.
    ListNode* sortListRecursive(ListNode* head) {
        if (!head || !head->next) return head;

        // Find midpoint via slow/fast pointers: O(n)
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split at midpoint
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Recurse on both halves: O(log n) depth
        ListNode* left = sortListRecursive(head);
        ListNode* right = sortListRecursive(mid);

        return mergeTwoLists(left, right);
    }

private:
    // Split list after `n` nodes; return head of remainder.
    ListNode* split(ListNode* head, int n) {
        for (int i = 1; head && i < n; ++i)
            head = head->next;
        if (!head) return nullptr;
        ListNode* rest = head->next;
        head->next = nullptr;
        return rest;
    }

    // Merge two sorted lists, appending result after `prev`.
    // Returns the tail of the merged segment.
    ListNode* merge(ListNode* l, ListNode* r, ListNode* prev) {
        while (l && r) {
            if (l->val <= r->val) {
                prev->next = l;
                l = l->next;
            } else {
                prev->next = r;
                r = r->next;
            }
            prev = prev->next;
        }
        prev->next = l ? l : r;
        while (prev->next) prev = prev->next;
        return prev;
    }

    // Standard two-list merge for recursive version.
    ListNode* mergeTwoLists(ListNode* l, ListNode* r) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l && r) {
            if (l->val <= r->val) { tail->next = l; l = l->next; }
            else { tail->next = r; r = r->next; }
            tail = tail->next;
        }
        tail->next = l ? l : r;
        return dummy.next;
    }
};

#endif //LEET_CODE_SORTLIST_HPP
