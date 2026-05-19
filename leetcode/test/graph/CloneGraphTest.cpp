#include "gtest/gtest.h"
#include "graph/CloneGraph.hpp"

using namespace std;

// Build a graph from adjacency list (1-indexed). adjList[i] contains neighbors of node i+1.
static GNode* buildGraph(const vector<vector<int>> &adjList) {
    if (adjList.empty()) return nullptr;
    int n = adjList.size();
    vector<GNode*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new GNode(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int nb : adjList[i - 1]) {
            nodes[i]->neighbors.push_back(nodes[nb]);
        }
    }
    return nodes[1];
}

// Convert graph to adjacency list (1-indexed) for comparison via BFS.
static vector<vector<int>> toAdjList(GNode* node) {
    if (!node) return {};
    unordered_map<GNode*, int> visited;
    queue<GNode*> q;
    q.push(node);
    visited[node] = node->val;
    int maxVal = node->val;
    while (!q.empty()) {
        GNode* cur = q.front();
        q.pop();
        for (GNode* nb : cur->neighbors) {
            if (visited.find(nb) == visited.end()) {
                visited[nb] = nb->val;
                if (nb->val > maxVal) maxVal = nb->val;
                q.push(nb);
            }
        }
    }
    vector<vector<int>> result(maxVal);
    q.push(node);
    unordered_map<GNode*, bool> seen;
    seen[node] = true;
    while (!q.empty()) {
        GNode* cur = q.front();
        q.pop();
        for (GNode* nb : cur->neighbors) {
            result[cur->val - 1].push_back(nb->val);
            if (!seen[nb]) {
                seen[nb] = true;
                q.push(nb);
            }
        }
    }
    return result;
}

// Verify clone is a deep copy (no shared pointers with original).
static bool isDeepCopy(GNode* original, GNode* clone) {
    if (!original && !clone) return true;
    if (!original || !clone) return false;
    unordered_map<GNode*, bool> origNodes;
    queue<GNode*> q;
    q.push(original);
    origNodes[original] = true;
    while (!q.empty()) {
        GNode* cur = q.front();
        q.pop();
        for (GNode* nb : cur->neighbors) {
            if (!origNodes[nb]) {
                origNodes[nb] = true;
                q.push(nb);
            }
        }
    }
    // Check that no clone node pointer exists in original set.
    queue<GNode*> q2;
    unordered_map<GNode*, bool> cloneNodes;
    q2.push(clone);
    cloneNodes[clone] = true;
    while (!q2.empty()) {
        GNode* cur = q2.front();
        q2.pop();
        if (origNodes.count(cur)) return false;
        for (GNode* nb : cur->neighbors) {
            if (!cloneNodes[nb]) {
                cloneNodes[nb] = true;
                q2.push(nb);
            }
        }
    }
    return true;
}

TEST(graph, clone_graph_dfs) {
    CloneGraphSolution sol;

    // 4-node cycle: 1--2--3--4--1, plus 1--3 and 2--4 (LeetCode example)
    vector<vector<int>> adj1 = {{2,4},{1,3},{2,4},{3,1}};
    GNode* g1 = buildGraph(adj1);
    GNode* c1 = sol.cloneGraphDFS(g1);
    ASSERT_EQ(toAdjList(c1), adj1);
    ASSERT_TRUE(isDeepCopy(g1, c1));

    // Single node, no neighbors
    vector<vector<int>> adj2 = {{}};
    GNode* g2 = buildGraph(adj2);
    GNode* c2 = sol.cloneGraphDFS(g2);
    ASSERT_EQ(toAdjList(c2), adj2);
    ASSERT_TRUE(isDeepCopy(g2, c2));

    // Null input
    ASSERT_EQ(sol.cloneGraphDFS(nullptr), nullptr);

    // Two connected nodes
    vector<vector<int>> adj3 = {{2},{1}};
    GNode* g3 = buildGraph(adj3);
    GNode* c3 = sol.cloneGraphDFS(g3);
    ASSERT_EQ(toAdjList(c3), adj3);
    ASSERT_TRUE(isDeepCopy(g3, c3));
}

TEST(graph, clone_graph_bfs) {
    CloneGraphSolution sol;

    // 4-node cycle
    vector<vector<int>> adj1 = {{2,4},{1,3},{2,4},{3,1}};
    GNode* g1 = buildGraph(adj1);
    GNode* c1 = sol.cloneGraphBFS(g1);
    ASSERT_EQ(toAdjList(c1), adj1);
    ASSERT_TRUE(isDeepCopy(g1, c1));

    // Single node, no neighbors
    vector<vector<int>> adj2 = {{}};
    GNode* g2 = buildGraph(adj2);
    GNode* c2 = sol.cloneGraphBFS(g2);
    ASSERT_EQ(toAdjList(c2), adj2);
    ASSERT_TRUE(isDeepCopy(g2, c2));

    // Null input
    ASSERT_EQ(sol.cloneGraphBFS(nullptr), nullptr);

    // Two connected nodes
    vector<vector<int>> adj3 = {{2},{1}};
    GNode* g3 = buildGraph(adj3);
    GNode* c3 = sol.cloneGraphBFS(g3);
    ASSERT_EQ(toAdjList(c3), adj3);
    ASSERT_TRUE(isDeepCopy(g3, c3));
}
