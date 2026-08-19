#ifndef ADD_TWO_NUMBERS_HPP
#define ADD_TWO_NUMBERS_HPP

#include "struct/ListNode.hpp"

using namespace std;

/// LeetCode 2, medium, tags: linked list, math, recursion.
class SolutionAddTwoNumbers {
public:
    /// Iterative with dummy head. Time O(max(m,n)), Space O(1) extra.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        return dummy.next;
    }

    /// Recursive approach. Time O(max(m,n)), Space O(max(m,n)) stack.
    ListNode* addTwoNumbersRecursive(ListNode* l1, ListNode* l2, int carry = 0) {
        if (!l1 && !l2 && !carry) return nullptr;
        int sum = carry;
        if (l1) sum += l1->val;
        if (l2) sum += l2->val;
        ListNode* node = new ListNode(sum % 10);
        node->next = addTwoNumbersRecursive(
            l1 ? l1->next : nullptr,
            l2 ? l2->next : nullptr,
            sum / 10
        );
        return node;
    }
};

#endif
