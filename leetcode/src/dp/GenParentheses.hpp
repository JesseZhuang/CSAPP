#ifndef GENPARENTHESES_HPP
#define GENPARENTHESES_HPP
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// solution 1, Backtracking. O(4^n/sqrt(n)) time and space.
class GenParenthesesBT {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtrack(res, cur, 0, 0, n);
        return res;
    }

private:
    void backtrack(vector<string>& res, string& cur, int left, int right, int n) {
        if ((int)cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }
        if (left < n) {
            cur.push_back('(');
            backtrack(res, cur, left + 1, right, n);
            cur.pop_back();
        }
        if (right < left) {
            cur.push_back(')');
            backtrack(res, cur, left, right + 1, n);
            cur.pop_back();
        }
    }
};

// solution 2, DP decomposition f(k) = "(" + f(i) + ")" + f(k-1-i). O(4^n/sqrt(n)) time and space.
class GenParenthesesDP {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for (int k = 1; k <= n; k++)
            for (int i = 0; i < k; i++)
                for (const string& inside : dp[i])
                    for (const string& outside : dp[k - 1 - i])
                        dp[k].push_back("(" + inside + ")" + outside);
        return dp[n];
    }
};

#endif //GENPARENTHESES_HPP
