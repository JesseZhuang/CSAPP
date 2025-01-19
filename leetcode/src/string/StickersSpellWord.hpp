#ifndef LEETCODE_STICKERSSPELLWORD_HPP
#define LEETCODE_STICKERSSPELLWORD_HPP

#include <string>
#include <vector>

using namespace std;

// leet 691, 135 ms, 12.7 mb
class Solution {
public:
    int minStickers(vector<string> &stickers, string target) {
        int t = target.size(), m = 1 << t; // m=2^t-1 subset of characters
        vector<uint> dp(m, -1);
        dp[0] = 0; // dp[empty set] requires 0 stickers,
        for (int i = 0; i < m; i++) { // start from 0 (empty set) to 111111...(the target)
            if (dp[i] == -1) continue;
            for (string &s: stickers) {
                int cur = i;
                for (char c: s) {
                    for (int j = 0; j < t; j++) {
                        if (target[j] == c && !((cur >> j) & 1)) { // try on a missing char in the subset of target
                            cur |= 1 << j;
                            break;
                        }
                    }
                }
                dp[cur] = min(dp[cur], dp[i] + 1);
            }
        }
        return dp[m - 1]; // uint -1 will be cast to int -1
    }
};

#endif //LEETCODE_STICKERSSPELLWORD_HPP
