#ifndef LEETCODE_KDIFFPAIRS_HPP
#define LEETCODE_KDIFFPAIRS_HPP

#include <vector>
#include <unordered_map>

using namespace std;

// leet 532, 3 ms, 17.22 mb
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (auto &n: nums) cnt[n] += 1;
        for (auto e: cnt) res += k > 0 && cnt.count(e.first + k) || k == 0 && e.second > 1;
        return res;
    }
};

#endif //LEETCODE_KDIFFPAIRS_HPP
