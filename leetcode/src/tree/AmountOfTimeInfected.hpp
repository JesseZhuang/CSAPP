#ifndef AMOUNT_OF_TIME_INFECTED_HPP
#define AMOUNT_OF_TIME_INFECTED_HPP

#include "struct/TreeNode.hpp"
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

// BFS: build parent map, then BFS from start node
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = nullptr;

        // DFS to build parent map and find start node
        function<void(TreeNode*, TreeNode*)> buildParent = [&](TreeNode* node, TreeNode* par) {
            if (!node) return;
            parent[node] = par;
            if (node->val == start) startNode = node;
            buildParent(node->left, node);
            buildParent(node->right, node);
        };
        buildParent(root, nullptr);

        // BFS from startNode
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);
        int minutes = -1;

        while (!q.empty()) {
            int sz = q.size();
            minutes++;
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                for (TreeNode* next : {cur->left, cur->right, parent[cur]}) {
                    if (next && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return minutes;
    }
};

// DFS: encode distance as negative return value
class Solution2 {
    int ans;

    int depth(TreeNode* node, int start) {
        if (!node) return 0;
        int left = depth(node->left, start);
        int right = depth(node->right, start);

        if (node->val == start) {
            ans = max(left, right);
            return -1;
        }
        if (left < 0) {
            ans = max(ans, right - left);
            return left - 1;
        }
        if (right < 0) {
            ans = max(ans, left - right);
            return right - 1;
        }
        return max(left, right) + 1;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        ans = 0;
        depth(root, start);
        return ans;
    }
};

#endif //AMOUNT_OF_TIME_INFECTED_HPP
