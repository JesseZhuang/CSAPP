#ifndef REMOVE_NTH_FROM_END_HPP
#define REMOVE_NTH_FROM_END_HPP
#include "struct/ListNode.hpp"
using namespace std;

class SolutionRemoveNthFromEnd {
public:
    // Two pointer approach. O(n) time, O(1) space.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for (int i = 0; i <= n; ++i) fast = fast->next;
        while (fast) { fast = fast->next; slow = slow->next; }
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;
        return dummy.next;
    }

    // Counting approach. O(n) time, O(1) space.
    ListNode* removeNthFromEndCount(ListNode* head, int n) {
        ListNode dummy(0, head);
        int len = 0;
        for (ListNode* p = head; p; p = p->next) ++len;
        ListNode* prev = &dummy;
        for (int i = 0; i < len - n; ++i) prev = prev->next;
        ListNode* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        return dummy.next;
    }
};
#endif
