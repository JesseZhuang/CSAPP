#ifndef LEETCODE_CARFLEET_HPP
#define LEETCODE_CARFLEET_HPP

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution853 {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = static_cast<int>(position.size());
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { // O(n log n)
            return position[a] > position[b];
        });
        int res = 0;
        double cur = 0;
        for (int i : idx) { // O(n)
            double time = (double) (target - position[i]) / speed[i];
            if (time > cur) {
                cur = time;
                res++;
            }
        }
        return res; // Time O(n log n), Space O(n)
    }
};

#endif //LEETCODE_CARFLEET_HPP
