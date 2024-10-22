#ifndef LEETCODE_KTHCHARSTRINGGAMEII_HPP
#define LEETCODE_KTHCHARSTRINGGAMEII_HPP

#include <vector>
#include <bit>

using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int> &operations) {
        k--;
        int len = bit_width(static_cast<unsigned long>(k)), cnt = 0;
        for (int i = len - 1; i >= 0; i--)
            if (k >> i & 1) cnt += operations[i];
        return 'a' + cnt % 26;
    }
};

#endif //LEETCODE_KTHCHARSTRINGGAMEII_HPP
