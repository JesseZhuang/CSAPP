#ifndef LEETCODE_CHECKIFNDOUBLEEXIST_HPP
#define LEETCODE_CHECKIFNDOUBLEEXIST_HPP

#include <vector>
#include <unordered_set>

using namespace std;

// leet 1346, O(n) time and space.
class CheckIfNDoubleExist {
public:
    bool checkIfExist(vector<int> &arr) {
        unordered_set<int> seen;
        for (int n: arr) {
            if (seen.count(2 * n) || (n % 2 == 0 && seen.count(n / 2))) return true;
            seen.insert(n);
        }
        return false;
    }
};

#endif //LEETCODE_CHECKIFNDOUBLEEXIST_HPP
