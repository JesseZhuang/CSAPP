#ifndef LEETCODE_FINDLCPLENARRAYS_HPP
#define LEETCODE_FINDLCPLENARRAYS_HPP

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
    unordered_map<char, unique_ptr<Node>> next;
public:
    Node() = default;

    void insert(const string &w) {
        auto cur = this;
        for (auto &c: w) {
            if (!cur->next.count(c)) cur->next[c] = make_unique<Node>();
            cur = cur->next[c].get();
        }
    }

    int lcpLen(const string &w) {
        auto cur = this;
        int res = 0;
        for (auto &c: w) {
            if (!cur->next.count(c)) break;
            cur = cur->next[c].get();
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        int res = 0;
        auto root = make_unique<Node>();
        for (auto a: arr1) root->insert(to_string(a));
        for (auto a: arr2) res = max(res, root->lcpLen(to_string(a)));
        return res;
    }
};


#endif //LEETCODE_FINDLCPLENARRAYS_HPP
