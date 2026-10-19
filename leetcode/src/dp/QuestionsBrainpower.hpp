#ifndef QUESTIONSBRAINPOWER_HPP
#define QUESTIONSBRAINPOWER_HPP

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>> &questions) {
        const int n = static_cast<int>(questions.size());
        vector<long long> dp(n + 1, 0);
        for (int index = n - 1; index >= 0; --index) {
            const int next = min(n, index + questions[index][1] + 1);
            dp[index] = max(dp[index + 1], static_cast<long long>(questions[index][0]) + dp[next]);
        }
        return dp[0];
    }
};

#endif // QUESTIONSBRAINPOWER_HPP
