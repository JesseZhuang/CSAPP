#ifndef LEETCODE_CPH_HPP
#define LEETCODE_CPH_HPP


#include "bits/stdc++.hpp"

// competitive programming hacks

// @Kude
#pragma GCC optimize("O2")
//https://stackoverflow.com/questions/25311011/how-does-include-bits-stdc-h-work-in-c
//#include <bits/stdc++.h> // https://gist.github.com/Einstrasse/ac0fe7d7450621a39364ed3b05cacd11
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    } else return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    } else return false;
}

using ll = long long;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

#endif //LEETCODE_CPH_HPP
