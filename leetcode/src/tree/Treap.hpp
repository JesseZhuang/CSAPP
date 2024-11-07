#ifndef LEETCODE_TREAP_HPP
#define LEETCODE_TREAP_HPP

#include <cstdlib>
#include <algorithm>

using namespace std;

// https://cp-algorithms.com/data_structures/treap.html

struct item {
    int key, prior, cnt;
    item *l, *r;

    item() {}

    item(int key) : key(key), prior(rand()), l(nullptr), r(nullptr) {}

    item(int key, int prior) : key(key), prior(prior), l(nullptr), r(nullptr) {}
};

typedef item *pitem;

int cnt(pitem t) {
    return t ? t->cnt : 0;
}

void update_cnt(pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(pitem t, int key, pitem &l, pitem &r) {
    if (!t) l = r = nullptr;
    else if (t->key <= key) split(t->r, key, t->r, r), l = t;
    else split(t->l, key, l, t->l), r = t;
}

void insert(pitem &t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(t->key <= it->key ? t->r : t->l, it);
}

void merge(pitem &t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    update_cnt(t);
}

void erase(pitem &t, int key) {
    if (t->key == key) {
        pitem th = t;
        merge(t, t->l, t->r);
        delete th;
    } else
        erase(key < t->key ? t->l : t->r, key);
}

pitem unite(pitem l, pitem r) {
    if (!l || !r) return l ? l : r;
    if (l->prior < r->prior) swap(l, r);
    pitem lt, rt;
    split(r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    return l;
}


#endif //LEETCODE_TREAP_HPP
