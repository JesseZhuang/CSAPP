#include "Manacher.hpp"

#include <iostream>
#include <ostream>

using namespace std;

Manacher::Manacher(__1::string s): s(s) {
    // constructor will make a copy of s
    size_t n = s.length(), m = 2 * n + 3;
    t.resize(m); // constructor default empty, reserve allocate space still cannot index[]
    p.resize(m); // or just use emplace_back
    // preprocess
    t[0] = '$';
    for (int i = 0; i < n; i++) {
        t[2 * i + 1] = '#';
        t[2 * i + 2] = s[i];
    }
    t[2 * n + 1] = '#';
    t[2 * n + 2] = '@';
    // calculate p
    int c = 0, r = 0;
    for (int i = 1; i < m - 1; i++) {
        int mirror = 2 * c - i;
        if (r > i) p[i] = min(p[mirror], r - i);
        while (t[i + (1 + p[i])] == t[i - (1 + p[i])]) p[i]++;
        if (i + p[i] > r) {
            r = i + p[i];
            c = i;
        }
        if (i - (1 + p[i]) == 0) mppl = p[i];
    }
}

string Manacher::longestPalindromeSubstring() {
    int c = 0, l = 0;
    for (int i = 1; i < p.size() - 1; i++) {
        if (p[i] > l) {
            l = p[i];
            c = i;
        }
    }
    return string(s.substr(c - 1 - l, c - 1 + l));
}

int Manacher::cntPalindromeSubstrings() {
    int res = 0;
    for (int i = 1; i < p.size() - 1; i++) {
        res += (1 + p[i]) / 2;
    }
    return res;
}
