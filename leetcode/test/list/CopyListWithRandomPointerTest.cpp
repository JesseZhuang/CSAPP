#include "gtest/gtest.h"
#include "list/CopyListWithRandomPointer.hpp"

#include <vector>

using namespace std;

namespace {

// Build a list from values and random indices (-1 means nullptr).
RandomNode* buildList(const vector<int>& vals, const vector<int>& randomIdx) {
    if (vals.empty()) return nullptr;
    vector<RandomNode*> nodes;
    for (int v : vals) nodes.push_back(new RandomNode(v));
    for (size_t i = 0; i < nodes.size() - 1; ++i) nodes[i]->next = nodes[i + 1];
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (randomIdx[i] >= 0) nodes[i]->random = nodes[randomIdx[i]];
    }
    return nodes[0];
}

// Verify deep copy correctness: same values, same random structure, no shared pointers.
void verifyDeepCopy(RandomNode* original, RandomNode* copy) {
    if (!original) {
        ASSERT_EQ(nullptr, copy);
        return;
    }
    // Collect original and copy nodes
    vector<RandomNode*> origNodes, copyNodes;
    for (RandomNode* o = original; o; o = o->next) origNodes.push_back(o);
    for (RandomNode* c = copy; c; c = c->next) copyNodes.push_back(c);
    ASSERT_EQ(origNodes.size(), copyNodes.size());

    // Map original node -> index
    unordered_map<RandomNode*, int> origIndex;
    for (size_t i = 0; i < origNodes.size(); ++i) origIndex[origNodes[i]] = i;

    for (size_t i = 0; i < origNodes.size(); ++i) {
        ASSERT_EQ(origNodes[i]->val, copyNodes[i]->val);
        ASSERT_NE(origNodes[i], copyNodes[i]); // must be different objects
        if (origNodes[i]->random) {
            int ri = origIndex[origNodes[i]->random];
            ASSERT_EQ(copyNodes[i]->random, copyNodes[ri]);
        } else {
            ASSERT_EQ(nullptr, copyNodes[i]->random);
        }
    }
}

void freeList(RandomNode* head) {
    while (head) { RandomNode* nx = head->next; delete head; head = nx; }
}

void verify(const vector<int>& vals, const vector<int>& randomIdx) {
    SolutionCopyListWithRandomPointer sol;
    {
        RandomNode* orig = buildList(vals, randomIdx);
        RandomNode* copy = sol.copyRandomListHashMap(orig);
        verifyDeepCopy(orig, copy);
        freeList(orig);
        freeList(copy);
    }
    {
        RandomNode* orig = buildList(vals, randomIdx);
        RandomNode* copy = sol.copyRandomListInterleave(orig);
        verifyDeepCopy(orig, copy);
        freeList(orig);
        freeList(copy);
    }
}

}  // namespace

// LeetCode Example 1: [[7,null],[13,0],[11,4],[10,2],[1,0]]
TEST(list, copy_list_with_random_pointer_example1) {
    verify({7, 13, 11, 10, 1}, {-1, 0, 4, 2, 0});
}

// LeetCode Example 2: [[1,1],[2,1]]
TEST(list, copy_list_with_random_pointer_example2) {
    verify({1, 2}, {1, 1});
}

// LeetCode Example 3: [[3,null],[3,0],[3,null]]
TEST(list, copy_list_with_random_pointer_example3) {
    verify({3, 3, 3}, {-1, 0, -1});
}

// Empty list
TEST(list, copy_list_with_random_pointer_empty) {
    verify({}, {});
}

// Single node with no random
TEST(list, copy_list_with_random_pointer_single_no_random) {
    verify({42}, {-1});
}

// Single node with self-random
TEST(list, copy_list_with_random_pointer_single_self_random) {
    verify({5}, {0});
}

// All random pointers to last node
TEST(list, copy_list_with_random_pointer_all_random_to_last) {
    verify({1, 2, 3, 4}, {3, 3, 3, 3});
}

// Negative values
TEST(list, copy_list_with_random_pointer_negative_values) {
    verify({-10, -20, -30}, {2, 0, 1});
}
