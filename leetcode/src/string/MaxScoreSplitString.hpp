#ifndef LEETCODE_MAXSCORESPLITSTRING_HPP
#define LEETCODE_MAXSCORESPLITSTRING_HPP

#include <string>
#include <algorithm>

using namespace std;

// leet 1422, O(n) time, O(1) space.
class MaxScoreSplitString {
public:
    int maxScore(const string &s) {
        int res = 0, zero = 0, ones = 0;
        for (char c: s) if (c == '1') ones++;
        for (int i = 0; i < (int) s.size() - 1; i++) {
            if (s[i] == '0') zero++;
            else ones--;
            res = max(res, zero + ones);
        }
        return res;
    }
};

#endif //LEETCODE_MAXSCORESPLITSTRING_HPP
