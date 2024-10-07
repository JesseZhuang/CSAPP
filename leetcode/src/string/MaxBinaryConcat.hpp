#ifndef MAXBINARYCONCAT_HPP
#define MAXBINARYCONCAT_HPP

#include <algorithm>
#include <vector>

using namespace std;

// LeetCode 3309, medium, weekly 418 Q1
class Solution {
public:
    int maxGoodNumber(vector<int> &a) {
        sort(begin(a), end(a));
        int res = 0;
        do {
            int cur = 0;
            for (int x: a) {
                bool flag = false;
                for (int i = 10; i >= 0; --i) {
                    // element [1,127]
                    if (x & (1 << i)) flag = true; // start processing from the most significant one bit
                    if (flag) cur = cur * 2 + ((x >> i) & 1);
                }
            }
            res = max(res, cur);
        } while (next_permutation(begin(a), end(a)));
        return res;
    }
};


#endif //MAXBINARYCONCAT_HPP
