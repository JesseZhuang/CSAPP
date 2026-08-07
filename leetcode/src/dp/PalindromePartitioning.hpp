#ifndef PALINDROMEPARTITIONING_HPP
#define PALINDROMEPARTITIONING_HPP
#include <string>
#include <vector>

using namespace std;

// LeetCode 131: Palindrome Partitioning
// Backtracking + DP palindrome table precomputation
// Time: O(N * 2^N), Space: O(N^2)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        // Precompute palindrome table: dp[i][j] = true if s[i..j] is palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {          // O(N^2) fill
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, dp, path, result);
        return result;
    }

private:
    void backtrack(const string& s, int start,
                   const vector<vector<bool>>& dp,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        if (start == (int)s.size()) {
            result.push_back(path);
            return;
        }
        for (int end = start; end < (int)s.size(); end++) {  // O(2^N) branches
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, dp, path, result);
                path.pop_back();
            }
        }
    }
};

// Backtracking + inline palindrome check (no precomputation)
// Time: O(N * 2^N), Space: O(N) auxiliary (excluding output)
class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    bool isPalindrome(const string& s, int lo, int hi) {
        while (lo < hi) {                          // O(N) check per substring
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }

    void backtrack(const string& s, int start,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        if (start == (int)s.size()) {
            result.push_back(path);
            return;
        }
        for (int end = start; end < (int)s.size(); end++) {  // O(2^N) branches
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path, result);
                path.pop_back();
            }
        }
    }
};

#endif //PALINDROMEPARTITIONING_HPP
