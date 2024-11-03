#ifndef LEETCODE_ROTATESTRING_HPP
#define LEETCODE_ROTATESTRING_HPP

#include <vector>
#include <string>
#include "KMP1D.hpp"

using namespace std;

class Solution1 {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubleS = s + s;
        return KMP1D(goal).search(doubleS);
    }
};

class Solution2 {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false; // Lengths must match for rotation
        string combined = s + s; // Concatenate s with itself
        return combined.find(goal) != string::npos;
    }

};

#endif //LEETCODE_ROTATESTRING_HPP
