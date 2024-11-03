#ifndef LEETCODE_ROTATESTRING_HPP
#define LEETCODE_ROTATESTRING_HPP

#include <vector>
#include <string>
#include "KMP1D.hpp"

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubleS = s + s;
        return KMP1D(goal).search(doubleS);
    }
};

#endif //LEETCODE_ROTATESTRING_HPP
