#ifndef LEETCODE_NUMBEROFPROVINCES_HPP
#define LEETCODE_NUMBEROFPROVINCES_HPP

#include <vector>
#include <stack>
#include <numeric>

using namespace std;

class Solution {
public:
    // DFS iterative: count connected components using adjacency matrix.
    // Time: O(n^2) — visit every cell of the matrix once.
    // Space: O(n) — visited array + stack depth bounded by n.
    static int findCircleNumDFS(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false); // O(n) space for visited set
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue; // already part of a known province
            provinces++;
            stack<int> stk;        // O(n) worst-case stack depth
            stk.push(i);
            visited[i] = true;
            while (!stk.empty()) {
                int city = stk.top();
                stk.pop();
                for (int j = 0; j < n; j++) { // O(n) scan neighbors
                    if (isConnected[city][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        stk.push(j);
                    }
                }
            }
        }
        return provinces;
    }

    // Union Find with path compression + union by rank.
    // Time: O(n^2 * alpha(n)) — iterate matrix, each union/find nearly O(1).
    // Space: O(n) — parent and rank arrays.
    static int findCircleNumUF(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);   // O(n) space
        vector<int> rank(n, 0);  // O(n) space for union by rank
        iota(parent.begin(), parent.end(), 0); // parent[i] = i initially
        int provinces = n; // start with n components

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // upper triangle only
                if (isConnected[i][j] == 1) {
                    int ri = find(parent, i); // path-compressed find
                    int rj = find(parent, j);
                    if (ri != rj) {
                        unite(parent, rank, ri, rj); // union by rank
                        provinces--; // merging two components
                    }
                }
            }
        }
        return provinces;
    }

private:
    // Find with path compression — amortized O(alpha(n)).
    static int find(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path compression (halving)
            x = parent[x];
        }
        return x;
    }

    // Union by rank — keeps tree balanced.
    static void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;              // attach smaller tree under larger
        if (rank[x] == rank[y]) rank[x]++; // increase rank if equal
    }
};

#endif //LEETCODE_NUMBEROFPROVINCES_HPP
