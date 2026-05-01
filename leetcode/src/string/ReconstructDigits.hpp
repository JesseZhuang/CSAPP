#ifndef LEETCODE_RECONSTRUCTDIGITS_HPP
#define LEETCODE_RECONSTRUCTDIGITS_HPP

#include <string>

using namespace std;

// leet 423. O(n) time, O(1) space.
class Solution423 {
public:
    string originalDigits(const string &s) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        int res[10] = {};
        res[0] = cnt['z' - 'a'];
        res[2] = cnt['w' - 'a'];
        res[4] = cnt['u' - 'a'];
        res[6] = cnt['x' - 'a'];
        res[8] = cnt['g' - 'a'];
        res[1] = cnt['o' - 'a'] - (res[0] + res[2] + res[4]);
        res[3] = cnt['r' - 'a'] - (res[0] + res[4]);
        res[5] = cnt['f' - 'a'] - res[4];
        res[7] = cnt['s' - 'a'] - res[6];
        res[9] = cnt['i' - 'a'] - (res[5] + res[6] + res[8]);
        string result;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < res[i]; j++)
                result += to_string(i);
        return result;
    }
};

#endif //LEETCODE_RECONSTRUCTDIGITS_HPP
