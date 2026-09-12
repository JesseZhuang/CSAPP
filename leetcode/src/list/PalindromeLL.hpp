#ifndef PALINDROME_LL_HPP
#define PALINDROME_LL_HPP

#include "struct/ListNode.hpp"
#include <stack>

using namespace std;

/// LeetCode 234, easy, tags: linked list, two pointers, stack, recursion.
class SolutionPalindromeLL {
public:
    /// O(n) time, O(1) space. Reverse first half in-place, compare, restore.
    bool isPalindrome(ListNode* head) {
        ListNode* rev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) { // O(n/2)
            fast = fast->next->next;
            ListNode* temp = rev;
            rev = slow;
            slow = slow->next;
            rev->next = temp;
        }
        ListNode* tail = fast ? slow->next : slow; // odd: skip middle
        while (rev) { // O(n/2)
            if (tail->val != rev->val) return false;
            tail = tail->next;
            ListNode* temp = slow;
            slow = rev;
            rev = rev->next;
            slow->next = temp;
        }
        return true;
    }

    /// O(n) time, O(n) space. Stack-based: push first half, compare with second half.
    bool isPalindromeStack(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> stk;
        while (fast && fast->next) { // O(n/2)
            stk.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next; // odd: skip middle
        while (slow) { // O(n/2)
            if (stk.top() != slow->val) return false;
            stk.pop();
            slow = slow->next;
        }
        return true;
    }
};

#endif // PALINDROME_LL_HPP
