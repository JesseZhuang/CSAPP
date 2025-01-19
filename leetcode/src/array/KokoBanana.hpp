#ifndef LEETCODE_KOKOBANANA_HPP
#define LEETCODE_KOKOBANANA_HPP

#include <vector>

using namespace std;

// leet 875, 14 ms, 22.99 mb.
class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (feasible(piles, h, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    bool feasible(vector<int> &piles, int h, int speed) {
        int sum = 0;
        for (auto p: piles) sum += (p - 1) / speed + 1;
        return sum <= h;
    }
};

#endif //LEETCODE_KOKOBANANA_HPP
