#ifndef WORDBREAK_HPP
#define WORDBREAK_HPP
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// solution 1, DP with hash set. O(n^2*k) time, O(n+m*k) space.
// dp[i] = true if s[0..i) can be segmented into words in wordDict.
class WordBreakDP {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
        return dp[n];
    }
};

// solution 2, BFS with visited array. O(n^2*k) time, O(n+m*k) space.
class WordBreakBFS {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (visited[start]) continue;
            visited[start] = true;
            for (int end = start + 1; end <= n; end++) {
                if (dict.count(s.substr(start, end - start))) {
                    if (end == n) return true;
                    q.push(end);
                }
            }
        }
        return false;
    }
};

#endif //WORDBREAK_HPP
