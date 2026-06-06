#ifndef FIND_ALL_ANAGRAMS_HPP
#define FIND_ALL_ANAGRAMS_HPP

#include <string>
#include <vector>
using namespace std;

// leet 438, medium, tags: hash table, string, sliding window.
class FindAllAnagrams {
public:
    // Approach 1: sliding window with count array, check all zeros. O(26*n) time, O(1) space.
    static vector<int> findAnagrams(const string& s, const string& p) {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (n < m) return res;
        int cnt[26] = {};
        for (char c : p) cnt[c - 'a']++;
        for (int i = 0; i < n; ++i) { // O(n) iterations
            cnt[s[i] - 'a']--;
            if (i >= m) cnt[s[i - m] - 'a']++;
            if (i >= m - 1) {
                bool allZero = true;
                for (int j = 0; j < 26; ++j) { // O(26) check per window position
                    if (cnt[j] != 0) { allZero = false; break; }
                }
                if (allZero) res.push_back(i - m + 1);
            }
        }
        return res;
    }

    // Approach 2: sliding window tracking matches count. O(n) time, O(1) space.
    static vector<int> findAnagrams2(const string& s, const string& p) {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (n < m) return res;
        int cnt[26] = {};
        for (char c : p) cnt[c - 'a']++;
        int matches = 0;
        for (int j = 0; j < 26; ++j) if (cnt[j] == 0) matches++;
        for (int i = 0; i < n; ++i) { // O(n) iterations, O(1) work per iteration
            int idx = s[i] - 'a';
            cnt[idx]--;
            if (cnt[idx] == 0) matches++;
            else if (cnt[idx] == -1) matches--;
            if (i >= m) {
                int lidx = s[i - m] - 'a';
                cnt[lidx]++;
                if (cnt[lidx] == 0) matches++;
                else if (cnt[lidx] == 1) matches--;
            }
            if (matches == 26) res.push_back(i - m + 1);
        }
        return res;
    }
};

#endif
