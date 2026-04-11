#ifndef LEETCODE_DECODESTRING_HPP
#define LEETCODE_DECODESTRING_HPP

#include <string>
#include <stack>

using namespace std;

// Solution 1: Stack-based
// Time: O(n * max_k), Space: O(n)
class Solution394 {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        string cur;
        int k = 0;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                stk.push({cur, k});
                cur.clear();
                k = 0;
            } else if (c == ']') {
                auto [prev, cnt] = stk.top();
                stk.pop();
                string tmp;
                for (int i = 0; i < cnt; i++) tmp += cur;
                cur = prev + tmp;
            } else {
                cur += c;
            }
        }
        return cur;
    }
};

// Solution 2: Recursive descent
// Time: O(n * max_k), Space: O(n)
class Solution394V2 {
    int i;

    string decode(const string &s) {
        string res;
        while (i < (int)s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < (int)s.size() && isdigit(s[i]))
                    k = k * 10 + (s[i++] - '0');
                i++; // skip '['
                string inner = decode(s);
                i++; // skip ']'
                for (int j = 0; j < k; j++) res += inner;
            } else {
                res += s[i++];
            }
        }
        return res;
    }

public:
    string decodeString(string s) {
        i = 0;
        return decode(s);
    }
};

#endif //LEETCODE_DECODESTRING_HPP
