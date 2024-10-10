#ifndef COINLINEII_HPP
#define COINLINEII_HPP
#include <vector>

using namespace std;

// LintCode 395
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if (n < 3) return true;
        vector<int> sum(3, 0), f(3, 0);
        f[(n - 1) % 3] = sum[(n - 1) % 3] = values[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sum[i % 3] = sum[(i + 1) % 3] + values[i];
            f[i % 3] = max(
                values[i] + sum[(i + 1) % 3] - f[(i + 1) % 3],
                values[i] + values[i + 1] + sum[(i + 2) % 3] - f[(i + 2) % 3]
            );
        }
        return f[0] > sum[0] - f[0];
    }
};

#endif //COINLINEII_HPP
