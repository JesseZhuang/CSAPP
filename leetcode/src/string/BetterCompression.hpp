#ifndef LEETCODE_BETTERCOMPRESSION_HPP
#define LEETCODE_BETTERCOMPRESSION_HPP

#include <string>

using namespace std;

// leet 3167 HackerRank Better Compression. O(n) time, O(1) space.
class Solution3167 {
public:
    string betterCompression(const string &s) {
        int res[26] = {};
        int n = s.size(), i = 0;
        while (i < n) {
            int c = s[i] - 'a';
            i++;
            int cnt = 0;
            while (i < n && isdigit(s[i])) {
                cnt = cnt * 10 + (s[i] - '0');
                i++;
            }
            res[c] += cnt;
        }
        string result;
        for (int j = 0; j < 26; j++) {
            if (res[j] > 0) {
                result += (char) ('a' + j);
                result += to_string(res[j]);
            }
        }
        return result;
    }
};

#endif //LEETCODE_BETTERCOMPRESSION_HPP
