#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution2131 {
public:
    // lc 2131, greedy + hash, O(n) time, O(n) space.
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (auto& w : words) freq[w]++;

        int length = 0;
        bool hasCenter = false;

        for (auto& [word, cnt] : freq) {
            if (cnt == 0) continue;
            string rev = {word[1], word[0]};
            if (word == rev) {
                // palindromic word
                length += (cnt / 2) * 4;
                if (cnt % 2 == 1) hasCenter = true;
            } else if (word < rev && freq.count(rev)) {
                int pairs = min(cnt, freq[rev]);
                length += pairs * 4;
            }
        }

        if (hasCenter) length += 2;
        return length;
    }
};
