#ifndef LEETCODE_LASTSTONEWEIGHT_HPP
#define LEETCODE_LASTSTONEWEIGHT_HPP

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// leet 1046
class Solution {
public:
    // Time O(n log n), Space O(n)
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end()); // max-heap
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop(); // heaviest
            int b = pq.top(); pq.pop(); // second heaviest
            if (a != b)
                pq.push(a - b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

class Solution2 {
public:
    // Time O(n^2), Space O(n)
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end()); // sort ascending
        while (stones.size() > 1) {
            int a = stones.back(); stones.pop_back(); // heaviest
            int b = stones.back(); stones.pop_back(); // second heaviest
            if (a != b) {
                int diff = a - b;
                // insert diff in sorted position
                auto it = lower_bound(stones.begin(), stones.end(), diff);
                stones.insert(it, diff);
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};

#endif //LEETCODE_LASTSTONEWEIGHT_HPP
