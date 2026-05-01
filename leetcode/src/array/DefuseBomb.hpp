#ifndef DEFUSE_BOMB_HPP
#define DEFUSE_BOMB_HPP

#include <vector>
#include <cmath>
using namespace std;

// LeetCode 1652. Rolling sum. O(n) time, O(1) space (excluding result).
class DefuseBomb {
public:
    static vector<int> decrypt(vector<int>& code, int k) {
        int n = (int)code.size();
        vector<int> res(n, 0);
        if (k == 0) return res;
        int start = 1, end = k, sum = 0;
        if (k < 0) {
            start = n - abs(k);
            end = n - 1;
        }
        for (int i = start; i <= end; i++) sum += code[i];
        for (int i = 0; i < n; i++) {
            res[i] = sum;
            sum -= code[(start++) % n];
            sum += code[(end++ + 1) % n];
        }
        return res;
    }
};

#endif
