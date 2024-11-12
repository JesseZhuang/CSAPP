#ifndef LEETCODE_ITREAP_HPP
#define LEETCODE_ITREAP_HPP

#include <cstdio>
#include <algorithm>
#include <iostream>

// https://cp-algorithms.com/data_structures/treap.html
// https://usaco.guide/adv/treaps?lang=cpp
// implicit treap, considered an array with all following procedures O(lgn) in online mode

// Inserting an element in the array in any location
// Removal of an arbitrary element
// Finding sum, minimum / maximum element etc. on an arbitrary interval
// Addition, painting on an arbitrary interval
// Reversing elements on an arbitrary interval

using namespace std;

typedef struct item *pitem;

struct item {
    char v1;
    int prior, value, cnt;
    bool rev;
    pitem l, r;

    item(char c) : v1(c), prior(rand()), cnt(1), l(nullptr), r(nullptr) {}
};

int cnt(pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt(pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push(pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap(it->l, it->r);
        if (it->l) it->l->rev ^= true;
        if (it->r) it->r->rev ^= true;
    }
}

void merge(pitem &t, pitem l, pitem r) {
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}

void split(pitem t, pitem &l, pitem &r, int key, int add = 0) {
    if (!t)
        return void(l = r = nullptr);
    push(t);
    int cur_key = add + cnt(t->l); // implicit key of a node is the number of nodes less than it
    if (key <= cur_key)
        split(t->l, l, t->l, key, add), r = t;
    else
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    upd_cnt(t);
}

void reverse(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= true; // segment to reverse
    merge(t, t1, t2);
    merge(t, t, t3);
}

// in order traversal, no null, so cannot distinguish 0:2,1:[1,3] and 0:1,1:[2],2:[3]
ostream &operator<<(ostream &os, pitem n) {
    if (!n) return os;
    os << n->l;
    os << n->v1;
    os << n->r;
    return os;
}

void output(pitem t) {
    if (!t) return;
    push(t);
    output(t->l);
    printf("%d ", t->value);
    output(t->r);
}

#endif //LEETCODE_ITREAP_HPP
