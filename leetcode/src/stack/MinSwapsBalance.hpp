#pragma once

#include <string>

namespace MinSwapsBalance {

class Solution {
public:
    int minSwaps(const std::string& s) {
        int unmatchedOpen = 0;
        for (char bracket : s) {
            if (bracket == '[') {
                ++unmatchedOpen;
            } else if (unmatchedOpen > 0) {
                --unmatchedOpen;
            }
        }
        return (unmatchedOpen + 1) / 2;
    }
};

}
