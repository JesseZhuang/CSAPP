#ifndef LEETCODE_COUNTGOODSUBSEQUENCES_HPP
#define LEETCODE_COUNTGOODSUBSEQUENCES_HPP

#include <string>
#include <algorithm>

using namespace std;

// leet 2539
class Solution2539 {
    static constexpr int MOD = 1e9 + 7;
    static constexpr int N = 10001;
    long long f[N]{}, g[N]{};

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long comb(int n, int k) {
        return f[n] % MOD * g[k] % MOD * g[n - k] % MOD;
    }

public:
    Solution2539() {
        f[0] = g[0] = 1;
        for (int i = 1; i < N; i++) {
            f[i] = f[i - 1] * i % MOD;
            g[i] = power(f[i], MOD - 2);
        }
    }

    int countGoodSubsequences(string s) {
        int cnt[26] = {};
        int maxCnt = 0;
        for (char c : s) maxCnt = max(maxCnt, ++cnt[c - 'a']);
        long long ans = 0;
        for (int i = 1; i <= maxCnt; i++) {
            long long x = 1;
            for (int v : cnt)
                if (v >= i) x = x * ((comb(v, i) + 1) % MOD) % MOD;
            ans = (ans + x - 1) % MOD;
        }
        return (int) ans;
    }
};

#endif //LEETCODE_COUNTGOODSUBSEQUENCES_HPP
