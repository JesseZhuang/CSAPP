#ifndef LEET_CODE_LISTNODE_HPP
#define LEET_CODE_LISTNODE_HPP

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //LEET_CODE_LISTNODE_HPP
