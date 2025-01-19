#ifndef LEETCODE_VALIDWORDABBREVIATION_HPP
#define LEETCODE_VALIDWORDABBREVIATION_HPP

#include <string>

using namespace std;

// 20 ms, 2.82 mb. leet 408, lint 637
class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        int n = word.size(), m = abbr.size(), i = 0, j = 0, x = 0;
        while (i < n && j < m) {
            if (isdigit(abbr[j])) {
                if (x == 0 && abbr[j] == '0') return false;
                x = 10 * x + abbr[j] - '0';
            } else {
                i += x;
                x = 0;
                if (i >= n || abbr[j] != word[i]) return false;
                i++;
            }
            j++;
        }
        return i + x == n && j == m;
    }
};

#endif //LEETCODE_VALIDWORDABBREVIATION_HPP
