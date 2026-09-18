#ifndef MAXIMUM_TWIN_SUM_LINKED_LIST_HPP
#define MAXIMUM_TWIN_SUM_LINKED_LIST_HPP

#include "struct/ListNode.hpp"

#include <algorithm>
#include <stack>

using namespace std;

/// LeetCode 2130, medium, tags: linked list, two pointers, stack.
class SolutionMaximumTwinSumLinkedList {
public:
    /// Reverse second half approach. Time O(n), Space O(1).
    int pairSum(ListNode* head) {
        // Find middle with slow/fast pointers. O(n/2)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse second half starting at slow. O(n/2)
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nx = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nx;
        }
        // Pair up from head and reversed tail, track max. O(n/2)
        int maxSum = 0;
        ListNode* left = head;
        ListNode* right = prev;
        while (right) {
            maxSum = max(maxSum, left->val + right->val);
            left = left->next;
            right = right->next;
        }
        return maxSum;
    }

    /// Stack approach. Time O(n), Space O(n).
    int pairSumStack(ListNode* head) {
        // Push first half onto stack. O(n/2)
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        // Pop while traversing second half. O(n/2)
        int maxSum = 0;
        while (slow) {
            maxSum = max(maxSum, st.top() + slow->val);
            st.pop();
            slow = slow->next;
        }
        return maxSum;
    }
};

#endif
