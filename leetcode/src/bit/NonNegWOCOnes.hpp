#ifndef NONNEGWOCONES_HPP
#define NONNEGWOCONES_HPP

using namespace std;

// LeetCode 600

class Solution {
public:
    int findIntegers(int n) {
        int f[32]{};
        f[0] = 1;
        f[1] = 2; // 10xx or 0xxx
        for (int i = 2; i < 32; i++) f[i] = f[i - 1] + f[i - 2];
        bool prev = false;
        int res = 0;
        for (int k = 30; k >= 0; k--) {
            if (n & (1 << k)) {
                res += f[k];
                if (prev) return res;
                prev = true;
            } else prev = false;
        }
        return res + 1;
    }
};

#endif //NONNEGWOCONES_HPP
