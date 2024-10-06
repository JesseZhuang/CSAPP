#ifndef DIFFWAYSPAREN_HPP
#define DIFFWAYSPAREN_HPP

#include <utility>
#include <vector>
#include <string>

using namespace std;


class Solution {
    string e;
    vector<vector<vector<int> > > memo;

public:
    vector<int> diffWaysToCompute(string expression) {
        e = expression;
        const size_t n = e.length();
        memo.resize(n);
        for (size_t i = 0; i < n; i++) memo[i].resize(n);
        for (size_t i = 0; i < n; i++) {
            if (isdigit(e[i])) {
                int d1 = e[i] - '0';
                if (i + 1 < e.length() && isdigit(e[i + 1])) {
                    int d2 = e[i + 1] - '0';
                    memo[i][i + 1].push_back(d1 * 10 + d2);
                }
                memo[i][i].push_back(d1);
            }
        }
        for (auto len = 3; len <= n; len++)
            for (auto start = 0, end = start + len - 1; end < n; start++, end++)
                processSubexpression(start, end);
        return memo[0][n - 1];
    }

    void processSubexpression(size_t start, size_t end) {
        for (size_t split = start; split <= end; split++) {
            if (isdigit(e[split])) continue;
            vector<int> left = memo[start][split - 1];
            vector<int> right = memo[split + 1][end];
            computeResult(e[split], left, right, memo[start][end]);
        }
    }

    void computeResult(char op, vector<int> &left, vector<int> &right, vector<int> &res) {
        for (int lv: left) {
            for (int rv: right) {
                if (op == '+') res.push_back(lv + rv);
                else if (op == '-') res.push_back(lv - rv);
                else if (op == '*') res.push_back(lv * rv);
            }
        }
    }
};


#endif //DIFFWAYSPAREN_HPP
