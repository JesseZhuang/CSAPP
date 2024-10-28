#ifndef LEETCODE_ORIGTYPEDSTRINGII_HPP
#define LEETCODE_ORIGTYPEDSTRINGII_HPP

#include <vector>

using namespace std;

// dp[i][j] i: possibilities for character groups in w[0,i], string size at most j. @theabbie
class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int M = 1e9 + 7;
        size_t n = word.size();
        long long res = 1;
        vector<int> w;
        size_t i = 0;
        while (i < n) {
            int ctr = 1;
            while (i < n - 1 && word[i] == word[i + 1]) {
                i++;
                ctr++;
            }
            res = (res * ctr) % M;
            w.push_back(ctr);
            i++;
        }
        if (k <= w.size()) return static_cast<int>(res);
        vector<long long> dp(k, 1), ndp(k);
        // why k+2?, iterate i (character groups) backwards
        for (int cnt: w) {
            vector<long long> pf(k + 1, 0);
            for (int j = 0; j < k; j++) pf[j + 1] = (pf[j] + dp[j]) % M; // prefix sum
            for (int rem = 0; rem < k; rem++) {
                int x = min(cnt, rem);
                ndp[rem] = (pf[rem] - pf[rem - x] + M) % M;
            }
            dp = ndp;
        }
        res = (res - dp[k - 1] + M) % M;
        return static_cast<int>(res);
    }
};

#endif //LEETCODE_ORIGTYPEDSTRINGII_HPP
