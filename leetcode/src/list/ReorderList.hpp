#ifndef REORDER_LIST_HPP
#define REORDER_LIST_HPP

#include "struct/ListNode.hpp"

#include <stack>

using namespace std;

/// LeetCode 143, medium, tags: linked list, two pointers, stack.
class SolutionReorderList {
public:
    /// Find middle, reverse second half, merge. Time O(n), Space O(1).
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        // 1. Find middle (slow stops at end of first half)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2. Reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (second) {
            ListNode* nx = second->next;
            second->next = prev;
            prev = second;
            second = nx;
        }
        // 3. Merge two halves
        ListNode* first = head;
        second = prev;
        while (second) {
            ListNode* fn = first->next;
            ListNode* sn = second->next;
            first->next = second;
            second->next = fn;
            first = fn;
            second = sn;
        }
    }

    /// Stack-based approach. Time O(n), Space O(n).
    void reorderListStack(ListNode* head) {
        if (!head || !head->next) return;
        stack<ListNode*> stk;
        ListNode* cur = head;
        int len = 0;
        while (cur) { stk.push(cur); cur = cur->next; len++; }
        cur = head;
        int half = len / 2;
        for (int i = 0; i < half; i++) {
            ListNode* tail = stk.top(); stk.pop();
            ListNode* nx = cur->next;
            cur->next = tail;
            tail->next = nx;
            cur = nx;
        }
        cur->next = nullptr;
    }
};

#endif
