#ifndef LONGESTSTRINGCHAIN_HPP
#define LONGESTSTRINGCHAIN_HPP
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// LeetCode 1048 - Longest String Chain
// Sort words by length, DP on predecessors.
// O(n * L^2) time, O(n * L) space. n: words.size(), L: max word length.
class Solution {
public:
    int longestStrChain(vector<string> &words) {
        // Sort by length so predecessors are processed first. O(n log n)
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp; // dp[word] = longest chain ending at word
        int ans = 1;
        for (const string &word : words) { // O(n)
            dp[word] = 1;
            for (int i = 0; i < (int)word.size(); i++) { // O(L) removals
                // Build predecessor by removing char at i. O(L) string copy.
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(pred)) {
                    dp[word] = max(dp[word], dp[pred] + 1);
                }
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};

#endif //LONGESTSTRINGCHAIN_HPP
