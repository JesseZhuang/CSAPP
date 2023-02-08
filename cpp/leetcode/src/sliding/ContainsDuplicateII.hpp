#ifndef LEET_CODE_CONTAINSDUPLICATEII_HPP
#define LEET_CODE_CONTAINSDUPLICATEII_HPP

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) { // 189ms, 72.4Mb
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) s.erase(nums[i - k]);
            if (s.count(nums[i])) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};


#endif //LEET_CODE_CONTAINSDUPLICATEII_HPP
