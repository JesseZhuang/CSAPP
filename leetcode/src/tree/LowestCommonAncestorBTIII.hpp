#ifndef LEETCODE_LOWESTCOMMONANCESTORBTIII_HPP
#define LEETCODE_LOWESTCOMMONANCESTORBTIII_HPP

// leet 1650, lint 474

struct ParentNode {
    int val;
    ParentNode *left;
    ParentNode *right;
    ParentNode *parent;

    ParentNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class SolutionLCAIII {
public:
    ParentNode *lowestCommonAncestor(ParentNode *p, ParentNode *q) {
        ParentNode *a = p, *b = q;
        while (a != b) {
            a = a->parent ? a->parent : q;
            b = b->parent ? b->parent : p;
        }
        return a;
    }
};

#endif //LEETCODE_LOWESTCOMMONANCESTORBTIII_HPP
