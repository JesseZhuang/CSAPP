#ifndef LEETCODE_CLONEGRAPH_HPP
#define LEETCODE_CLONEGRAPH_HPP

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class GNode {
public:
    int val;
    vector<GNode*> neighbors;
    GNode() : val(0), neighbors(vector<GNode*>()) {}
    GNode(int _val) : val(_val), neighbors(vector<GNode*>()) {}
    GNode(int _val, vector<GNode*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class CloneGraphSolution {
public:
    // DFS approach: recursively clone each node and its neighbors.
    // Time: O(V+E), Space: O(V) for the visited map and recursion stack.
    GNode* cloneGraphDFS(GNode* node) {
        unordered_map<GNode*, GNode*> visited;
        return dfs(node, visited);
    }

    // BFS approach: iteratively clone each node and its neighbors.
    // Time: O(V+E), Space: O(V) for the visited map and queue.
    GNode* cloneGraphBFS(GNode* node) {
        if (!node) return nullptr;
        unordered_map<GNode*, GNode*> visited;
        queue<GNode*> q;
        visited[node] = new GNode(node->val);
        q.push(node);
        while (!q.empty()) {
            GNode* cur = q.front();
            q.pop();
            for (GNode* neighbor : cur->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new GNode(neighbor->val);
                    q.push(neighbor);
                }
                visited[cur]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }

private:
    GNode* dfs(GNode* node, unordered_map<GNode*, GNode*> &visited) {
        if (!node) return nullptr;
        if (visited.find(node) != visited.end()) return visited[node];
        GNode* clone = new GNode(node->val);
        visited[node] = clone;
        for (GNode* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }
        return clone;
    }
};

#endif //LEETCODE_CLONEGRAPH_HPP
