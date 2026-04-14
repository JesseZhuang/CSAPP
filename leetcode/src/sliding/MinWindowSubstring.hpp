#ifndef MIN_WINDOW_SUBSTRING_HPP
#define MIN_WINDOW_SUBSTRING_HPP

#include <string>
#include <algorithm>
using namespace std;

// leet 76, hard, tags: hash table, string, sliding window.
class MinWindowSubstring {
public:
    // sliding window with count tracking. O(m+n) time, O(128) space.
    static string minWindow(const string& s, const string& t) {
        int cnt[128] = {};
        for (char c : t) cnt[c]++;
        int notFound = t.size(), left = 0, minL = 0, minR = s.size() + 1;
        for (int right = 0; right < (int)s.size(); ++right) {
            if (cnt[s[right]]-- > 0) notFound--;
            while (notFound == 0) {
                if (right - left + 1 < minR - minL) {
                    minL = left;
                    minR = right + 1;
                }
                if (cnt[s[left++]]++ == 0) notFound++;
            }
        }
        return minR == (int)s.size() + 1 ? "" : s.substr(minL, minR - minL);
    }
};

#endif
