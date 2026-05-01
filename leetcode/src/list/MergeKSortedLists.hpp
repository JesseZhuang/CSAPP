#ifndef MERGE_K_SORTED_LISTS_HPP
#define MERGE_K_SORTED_LISTS_HPP

#include "struct/ListNode.hpp"

#include <queue>
#include <vector>

using namespace std;

/// LeetCode 23 / LintCode 104, hard, tags: heap, divide and conquer, linked list.
class SolutionMergeKSortedLists {
public:
    /// Min-heap of current heads. Time O(N log k), Space O(k).
    ListNode* mergeKListsHeap(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; }; // min-heap
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (ListNode* n : lists) if (n) pq.push(n);
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (!pq.empty()) {
            ListNode* n = pq.top(); pq.pop();
            cur->next = n;
            cur = cur->next;
            if (n->next) pq.push(n->next);
        }
        return dummy.next;
    }

    /// Pairwise merge bottom-up. Time O(N log k), Space O(1) (mutates input).
    ListNode* mergeKListsDivideConquer(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int n = (int)lists.size();
        for (int interval = 1; interval < n; interval *= 2) {
            for (int i = 0; i + interval < n; i += 2 * interval) {
                lists[i] = mergeTwo(lists[i], lists[i + interval]);
            }
        }
        return lists[0];
    }

private:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (a && b) {
            if (a->val < b->val) { cur->next = a; a = a->next; }
            else                 { cur->next = b; b = b->next; }
            cur = cur->next;
        }
        cur->next = a ? a : b;
        return dummy.next;
    }
};

#endif
