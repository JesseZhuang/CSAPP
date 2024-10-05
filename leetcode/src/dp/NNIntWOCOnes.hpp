#ifndef NNINTWOCONES_HPP
#define NNINTWOCONES_HPP


class Solution {
public:
    int findIntegers(int n) {
        int dp[32]{};
        dp[0] = 1;
        dp[1] = 2; // 10xx or 0xxx
        for (int i = 2; i < 32; i++) dp[i] = dp[i - 1] + dp[i - 2];
        bool prev = false;
        int res = 0;
        for (int k = 30; k >= 0; k--) {
            if (n & 1 << k) {
                res += dp[k];
                if (prev) return res;
                prev = true;
            } else prev = false;
        }
        return res + 1;
    }
};


#endif //NNINTWOCONES_HPP
