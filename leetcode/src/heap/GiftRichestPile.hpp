#ifndef LEETCODE_GIFTRICHESTPILE_HPP
#define LEETCODE_GIFTRICHESTPILE_HPP

#include <vector>
#include <queue>

using namespace std;

// leet 2558, 6ms, 13.4 mb
class Solution {
public:
    long long pickGifts(vector<int> &gifts, int k) {
        priority_queue<int> pq{gifts.begin(), gifts.end()};
        while (k-- > 0) {
            int cur = pq.top();
            pq.pop();
            pq.emplace(sqrt(cur)); // auto cast, floor to int
        }
        long long res = 0;
        while (!pq.empty())
            res += pq.top(), pq.pop();
        return res;
    }
};

#endif //LEETCODE_GIFTRICHESTPILE_HPP
