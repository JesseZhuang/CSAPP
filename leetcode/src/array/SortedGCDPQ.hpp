
#ifndef SORTEDGCDPQ_HPP
#define SORTEDGCDPQ_HPP

#include <vector>
#include <algorithm>

using namespace std;

// LeetCode 3312, weekly 418 Q4
class Solution {
public:
    vector<int> gcdValues(vector<int>& a, vector<long long>& queries) {
        const int M = 5e4 + 10;
        vector<long long> freq(M);
        for (int x : a) freq[x] += 1;
        for (int i = 1; i < M; ++i) for (int j = 2*i; j < M; j += i)
            freq[i] += freq[j];
        vector<long long> dp(M);
        for (int i = M-1; i >= 1; --i) {
            dp[i] = freq[i] * (freq[i]-1)/2;
            for (int j = 2*i; j < M; j += i) dp[i] -= dp[j];
        }
        for (int i = 2; i < M; ++i) dp[i] += dp[i-1];

        vector<int> res;
        for (auto k : queries) {
            auto it = upper_bound(begin(dp), end(dp), k);
            res.push_back(it - begin(dp));
        }
        return res;
    }
};



#endif //SORTEDGCDPQ_HPP
