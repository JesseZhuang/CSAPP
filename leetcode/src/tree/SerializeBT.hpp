#pragma once

#include "../struct/TreeNode.hpp"
#include <string>
#include <sstream>
#include <queue>

class SerializeBT {
public:
    // DFS preorder serialization - O(n) time, O(h) space
    std::string serialize_dfs(TreeNode* root) {
        std::string result;
        dfs_helper(root, result);
        if (!result.empty()) result.pop_back(); // remove trailing comma
        return result;
    }

    // DFS deserialization - O(n) time, O(n) space
    TreeNode* deserialize_dfs(std::string data) {
        std::istringstream ss(data);
        return dfs_build(ss);
    }

    // BFS level-order serialization - O(n) time, O(n) space
    std::string serialize_bfs(TreeNode* root) {
        if (!root) return "#";
        std::string result;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                result += std::to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "#,";
            }
        }
        if (!result.empty()) result.pop_back();
        return result;
    }

    // BFS deserialization - O(n) time, O(n) space
    TreeNode* deserialize_bfs(std::string data) {
        if (data.empty() || data == "#") return nullptr;
        std::istringstream ss(data);
        std::string token;
        std::getline(ss, token, ',');
        TreeNode* root = new TreeNode(std::stoi(token));
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (std::getline(ss, token, ',')) {
                if (token != "#") {
                    node->left = new TreeNode(std::stoi(token));
                    q.push(node->left);
                }
            }
            if (std::getline(ss, token, ',')) {
                if (token != "#") {
                    node->right = new TreeNode(std::stoi(token));
                    q.push(node->right);
                }
            }
        }
        return root;
    }

private:
    void dfs_helper(TreeNode* node, std::string& result) {
        if (!node) {
            result += "#,";
            return;
        }
        result += std::to_string(node->val) + ",";
        dfs_helper(node->left, result);
        dfs_helper(node->right, result);
    }

    TreeNode* dfs_build(std::istringstream& ss) {
        std::string token;
        if (!std::getline(ss, token, ',')) return nullptr;
        if (token == "#") return nullptr;
        TreeNode* node = new TreeNode(std::stoi(token));
        node->left = dfs_build(ss);
        node->right = dfs_build(ss);
        return node;
    }
};
