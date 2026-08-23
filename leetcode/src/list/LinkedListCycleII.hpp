#ifndef LINKED_LIST_CYCLE_II_HPP
#define LINKED_LIST_CYCLE_II_HPP

#include "struct/ListNode.hpp"
#include <unordered_set>

using namespace std;

/// LeetCode 142, medium, tags: hash table, linked list, two pointers.
class SolutionLinkedListCycleII {
public:
    /// Floyd's tortoise and hare. O(n) time, O(1) space.
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }

    /// HashSet approach. O(n) time, O(n) space.
    ListNode* detectCycleHash(ListNode* head) {
        unordered_set<ListNode*> seen;
        ListNode* cur = head;
        while (cur) {
            if (seen.count(cur)) return cur;
            seen.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};

#endif
