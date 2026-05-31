#ifndef COPY_LIST_WITH_RANDOM_POINTER_HPP
#define COPY_LIST_WITH_RANDOM_POINTER_HPP

#include <unordered_map>

using namespace std;

struct RandomNode {
    int val;
    RandomNode* next;
    RandomNode* random;
    RandomNode(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

/// LeetCode 138, medium, tags: linked list, hash table.
class SolutionCopyListWithRandomPointer {
public:
    /// Hash Map approach. Time O(n), Space O(n).
    RandomNode* copyRandomListHashMap(RandomNode* head) {
        if (!head) return nullptr;
        unordered_map<RandomNode*, RandomNode*> map; // O(n) space for mapping old->new
        RandomNode* cur = head;
        while (cur) { // O(n) time: create all new nodes
            map[cur] = new RandomNode(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) { // O(n) time: assign next and random pointers
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }

    /// Interleaving approach. Time O(n), Space O(1).
    RandomNode* copyRandomListInterleave(RandomNode* head) {
        if (!head) return nullptr;
        // Step 1: interleave copied nodes. O(n) time, O(1) space.
        RandomNode* cur = head;
        while (cur) {
            RandomNode* copy = new RandomNode(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        // Step 2: assign random pointers for copies. O(n) time.
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next; // O(1) random lookup via interleaving
            cur = cur->next->next;
        }
        // Step 3: separate the two lists. O(n) time.
        RandomNode* newHead = head->next;
        cur = head;
        while (cur) {
            RandomNode* copy = cur->next;
            cur->next = copy->next;
            copy->next = copy->next ? copy->next->next : nullptr;
            cur = cur->next;
        }
        return newHead;
    }
};

#endif
