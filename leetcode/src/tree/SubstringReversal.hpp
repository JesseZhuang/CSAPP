#ifndef LEETCODE_SUBSTRINGREVERSAL_HPP
#define LEETCODE_SUBSTRINGREVERSAL_HPP

#include <string>
#include <vector>
#include <utility>
#include "tree/ITreap.hpp"

using namespace std;

/**
 cses 2073 substring reversals, https://cses.fi/problemset/task/2073/

 Given a string, your task is to process operations where you reverse a substring of the string. What is the
  final string after all the operations?

Input
The first input line has two integers n and m: the length of the string and the number of operations.
 The characters of the string are numbered 1,2,\dots,n.
The next line has a string of length n that consists of characters A–Z.
Finally, there are m lines that describe the operations. Each line has two integers a and b:
 you reverse a substring from position a to position b.

Output
Print the final string after all the operations.
Constraints

1 \le n, m \le 2 \cdot 10^5
1 \le a \le b \le n

Example
Input:
7 2
AYBABTU
3 4
4 7

Output:
AYAUTBB
 */
class Solution {
    void collect(vector<char> &res, pitem root) { // important take vector by ref, not copy value!
        if (!root) return;
        collect(res, root->l);
        res.emplace_back(root->v1);
        collect(res, root->r);
    }

public:
    string reverse_ss(string s, vector<pair<int, int>> op) {
        pitem root = nullptr; // init important, otherwise undefined init values
        for (char c: s) merge(root, root, new item(c));
        for (auto [l, r]: op) reverse(root, l - 1, r - 1);
//        cout << root << endl;
        vector<char> res;
        collect(res, root);
        return string{res.begin(), res.end()};
    }
};

#endif //LEETCODE_SUBSTRINGREVERSAL_HPP
