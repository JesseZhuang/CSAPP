#ifndef LEETCODE_SHORTESTWAYFORMSTRING_HPP
#define LEETCODE_SHORTESTWAYFORMSTRING_HPP

#include <string>

using namespace std;

// leet 1055, lint 3652
class SolutionShortestWay {
public:
    int shortestWay(const string &source, const string &target) {
        int m = source.size(), n = target.size();
        int res = 0, j = 0;
        while (j < n) {
            bool found = false;
            int i = 0;
            while (i < m && j < n) {
                if (source[i] == target[j]) {
                    found = true;
                    j++;
                }
                i++;
            }
            if (!found) return -1;
            res++;
        }
        return res;
    }
};

#endif //LEETCODE_SHORTESTWAYFORMSTRING_HPP
