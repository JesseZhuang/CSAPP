#ifndef LEETCODE_POPULATINGNEXTRIGHTPOINTERSII_HPP
#define LEETCODE_POPULATINGNEXTRIGHTPOINTERSII_HPP

#include <queue>

namespace populating_next_right_pointers_ii {

struct Node {
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *next = nullptr;
};

class Solution {
public:
    // O(n) time and O(width) extra space for the queue.
    Node *connect(Node *root) {
        if (!root) return nullptr;

        std::queue<Node *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            Node *previous = nullptr;
            for (auto remaining = nodes.size(); remaining > 0; --remaining) {
                Node *current = nodes.front();
                nodes.pop();

                if (previous) previous->next = current;
                previous = current;
                if (current->left) nodes.push(current->left);
                if (current->right) nodes.push(current->right);
            }
            previous->next = nullptr;
        }
        return root;
    }

    // O(n) time and O(1) extra space using the current level's next chain.
    Node *connectConstantSpace(Node *root) {
        if (!root) return nullptr;

        root->next = nullptr;
        Node *level = root;
        while (level) {
            Node dummy{};
            Node *tail = &dummy;
            for (Node *current = level; current; current = current->next) {
                if (current->left) {
                    tail->next = current->left;
                    tail = tail->next;
                }
                if (current->right) {
                    tail->next = current->right;
                    tail = tail->next;
                }
            }
            tail->next = nullptr;
            level = dummy.next;
        }
        return root;
    }
};

}

#endif // LEETCODE_POPULATINGNEXTRIGHTPOINTERSII_HPP
