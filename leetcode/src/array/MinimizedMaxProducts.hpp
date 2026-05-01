#ifndef MINIMIZED_MAX_PRODUCTS_HPP
#define MINIMIZED_MAX_PRODUCTS_HPP

#include <vector>
using namespace std;

// LeetCode 2064. Binary search. O(n*log(k)) time, O(1) space.
class MinimizedMaxProducts {
public:
    static int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = 100000;
        while (left < right) {
            int mid = (left + right) / 2, sum = 0;
            for (int q : quantities) sum += (q + mid - 1) / mid;
            if (sum > n) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

#endif
