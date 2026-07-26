#ifndef LEETCODE_EVALUATEDIVISION_HPP
#define LEETCODE_EVALUATEDIVISION_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

namespace lc399 {

class Solution {
public:
    // BFS on weighted directed graph.
    // Time: O(Q * (V + E)), Space: O(V + E)
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        // Build adjacency list: a -> [(b, a/b), ...], b -> [(a, b/a), ...]
        unordered_map<string, vector<pair<string, double>>> graph;
        for (size_t i = 0; i < equations.size(); ++i) {
            const string &a = equations[i][0];
            const string &b = equations[i][1];
            double val = values[i];
            graph[a].emplace_back(b, val);
            graph[b].emplace_back(a, 1.0 / val);
        }

        vector<double> result;
        result.reserve(queries.size());
        for (auto &q : queries) {
            const string &src = q[0];
            const string &dst = q[1];
            if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) {
                result.push_back(-1.0);
                continue;
            }
            if (src == dst) {
                result.push_back(1.0);
                continue;
            }
            // BFS
            unordered_map<string, double> visited;
            queue<pair<string, double>> bfs;
            bfs.push({src, 1.0});
            visited[src] = 1.0;
            double ans = -1.0;
            while (!bfs.empty()) {
                auto [node, w] = bfs.front();
                bfs.pop();
                if (node == dst) {
                    ans = w;
                    break;
                }
                for (auto &[nei, nw] : graph[node]) {
                    if (visited.find(nei) == visited.end()) {
                        visited[nei] = w * nw;
                        bfs.push({nei, w * nw});
                    }
                }
            }
            result.push_back(ans);
        }
        return result;
    }

    // Union-Find with weighted edges.
    // weight[x] = x / root(x). Query a/b = weight[a] / weight[b] if same root.
    // Time: O((E + Q) * alpha(n)), Space: O(V)
    vector<double> calcEquationUnionFind(vector<vector<string>> &equations,
                                         vector<double> &values,
                                         vector<vector<string>> &queries) {
        parent.clear();
        weight.clear();
        rank_.clear();

        for (size_t i = 0; i < equations.size(); ++i) {
            const string &a = equations[i][0];
            const string &b = equations[i][1];
            add(a);
            add(b);
            unite(a, b, values[i]);
        }

        vector<double> result;
        result.reserve(queries.size());
        for (auto &q : queries) {
            const string &a = q[0];
            const string &b = q[1];
            if (parent.find(a) == parent.end() || parent.find(b) == parent.end()) {
                result.push_back(-1.0);
            } else {
                string ra = find(a);
                string rb = find(b);
                if (ra != rb) {
                    result.push_back(-1.0);
                } else {
                    // a/root = weight[a], b/root = weight[b]
                    // a/b = weight[a] / weight[b]
                    result.push_back(weight[a] / weight[b]);
                }
            }
        }
        return result;
    }

private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight; // weight[x] = x / root(x)
    unordered_map<string, int> rank_;

    void add(const string &x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            weight[x] = 1.0;
            rank_[x] = 0;
        }
    }

    // Find with path compression, updating weights along the way.
    string find(const string &x) {
        if (parent[x] != x) {
            string root = find(parent[x]);
            // weight[x] = x / parent[x] * parent[x] / root = x / root
            weight[x] *= weight[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }

    // Unite a and b given that a / b = val.
    void unite(const string &a, const string &b, double val) {
        string ra = find(a);
        string rb = find(b);
        if (ra == rb) return;
        // After find: weight[a] = a/ra, weight[b] = b/rb
        // We want ra/rb: a/b = val => (weight[a] * ra) / (weight[b] * rb) ... no
        // a = weight[a] * ra (conceptually), b = weight[b] * rb
        // a/b = val => weight[a]/weight[b] * ra/rb = val => ra/rb = val * weight[b] / weight[a]
        double w = val * weight[b] / weight[a]; // ra / rb

        if (rank_[ra] < rank_[rb]) {
            parent[ra] = rb;
            weight[ra] = w; // ra / rb
        } else if (rank_[ra] > rank_[rb]) {
            parent[rb] = ra;
            weight[rb] = 1.0 / w; // rb / ra
        } else {
            parent[rb] = ra;
            weight[rb] = 1.0 / w;
            rank_[ra]++;
        }
    }
};

} // namespace lc399

#endif // LEETCODE_EVALUATEDIVISION_HPP
