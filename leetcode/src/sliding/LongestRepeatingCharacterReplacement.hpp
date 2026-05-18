#pragma once
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 424: Longest Repeating Character Replacement
// Sliding window approach, O(n) time, O(1) space (26-char freq array)
class SolutionLongestRepeatingCharacterReplacement {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {};
        int maxFreq = 0; // track max frequency in current window
        int res = 0;
        for (int l = 0, r = 0; r < (int)s.size(); r++) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']); // O(1) update
            // Window is valid when (window_len - maxFreq) <= k
            // i.e., number of chars to replace <= k
            while ((r - l + 1) - maxFreq > k) { // shrink window if invalid
                freq[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

// Binary search on answer length + sliding window check
// O(n log n) time, O(1) space
class SolutionLongestRepeatingCharacterReplacement2 {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int lo = 1, hi = n, ans = 1;
        while (lo <= hi) { // O(log n) iterations
            int mid = lo + (hi - lo) / 2;
            if (canAchieve(s, k, mid)) { // check if window of size mid is feasible
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    // Check if there exists a window of size `len` where
    // (len - maxFreq) <= k, using a sliding window. O(n) per call.
    bool canAchieve(const string& s, int k, int len) {
        int freq[26] = {};
        int maxFreq = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            freq[s[i] - 'A']++;
            if (i >= len) {
                freq[s[i - len] - 'A']--; // slide out left element
            }
            if (i >= len - 1) { // window is fully formed
                // Recompute max freq for current window — O(26) = O(1)
                maxFreq = *max_element(freq, freq + 26);
                if (len - maxFreq <= k) return true;
            }
        }
        return false;
    }
};
