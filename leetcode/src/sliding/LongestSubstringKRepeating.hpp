#ifndef LONGEST_SUBSTRING_K_REPEATING_HPP
#define LONGEST_SUBSTRING_K_REPEATING_HPP

#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

// leet 395, medium, tags: hash table, string, divide and conquer, sliding window.
class LongestSubstringKRepeating {
public:
    // divide and conquer. find char with freq < k, split on it, recurse.
    // Time O(26n)=O(n), Space O(26)=O(1).
    static int longestSubstring(const string& s, int k) {
        return dc(s, 0, s.size(), k);
    }

    // sliding window. enumerate target unique count 1..total_unique.
    // Time O(26n)=O(n), Space O(26)=O(1).
    static int longestSubstring2(const string& s, int k) {
        int totalUnique = unordered_set<char>(s.begin(), s.end()).size();
        int res = 0;
        for (int target = 1; target <= totalUnique; ++target) {
            int cnt[26] = {};
            int left = 0, unique = 0, kOrMore = 0;
            for (int right = 0; right < (int)s.size(); ++right) {
                int c = s[right] - 'a';
                if (cnt[c]++ == 0) unique++;
                if (cnt[c] == k) kOrMore++;
                while (unique > target) {
                    int l = s[left] - 'a';
                    if (cnt[l] == k) kOrMore--;
                    if (--cnt[l] == 0) unique--;
                    left++;
                }
                if (unique == target && kOrMore == target)
                    res = max(res, right - left + 1);
            }
        }
        return res;
    }

private:
    static int dc(const string& s, int start, int end, int k) {
        if (end - start < k) return 0;
        int cnt[26] = {};
        for (int i = start; i < end; ++i) cnt[s[i] - 'a']++;
        for (int i = start; i < end; ++i) {
            if (cnt[s[i] - 'a'] >= k) continue;
            // split on this char
            int j = i + 1;
            while (j < end && cnt[s[j] - 'a'] < k) j++;
            return max(dc(s, start, i, k), dc(s, j, end, k));
        }
        return end - start; // all chars meet threshold
    }
};

#endif
