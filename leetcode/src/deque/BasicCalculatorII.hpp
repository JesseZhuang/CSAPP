#ifndef LEETCODE_BASICCALCULATORII_HPP
#define LEETCODE_BASICCALCULATORII_HPP

#include <string>

using namespace std;

class Solution {
public:
    int calculate(const string &s) {
        int res = 0, cur = 0, last = 0;
        char preOp = '+';
        for (auto &c: (s + "##")) {
            if (isspace(c)) continue;
            if (isdigit(c)) cur = cur * 10 + (c - '0'); // paren to avoid overflow, see unit test
            else {
                if (preOp == '*') last *= cur;
                else if (preOp == '/') last /= cur;
                else {
                    res += last;
                    last = preOp == '+' ? cur : -cur;
                }
                preOp = c;
                cur = 0;
            }
        }
        return res;
    }
};

#endif //LEETCODE_BASICCALCULATORII_HPP
