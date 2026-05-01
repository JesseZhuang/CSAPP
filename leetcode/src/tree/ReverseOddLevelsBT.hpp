#ifndef LEETCODE_REVERSEODDLEVELSBT_HPP
#define LEETCODE_REVERSEODDLEVELSBT_HPP

#include <algorithm>

using namespace std;

struct TreeNode2415 {
    int val;
    TreeNode2415 *left;
    TreeNode2415 *right;

    TreeNode2415(int x) : val(x), left(nullptr), right(nullptr) {}
};

// leet 2415, DFS. O(n) time, O(log n) space.
class Solution2415 {
public:
    TreeNode2415 *reverseOddLevels(TreeNode2415 *root) {
        if (root) dfs(root->left, root->right, 1);
        return root;
    }

private:
    void dfs(TreeNode2415 *l, TreeNode2415 *r, int d) {
        if (!l || !r) return;
        if (d % 2 == 1) swap(l->val, r->val);
        dfs(l->left, r->right, d + 1);
        dfs(l->right, r->left, d + 1);
    }
};

#endif //LEETCODE_REVERSEODDLEVELSBT_HPP
