#ifndef MAX_SUM_DISTINCT_K_HPP
#define MAX_SUM_DISTINCT_K_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// LeetCode 2461. Sliding window with last-seen map. O(n) time, O(n) space.
class MaxSumDistinctK {
public:
    static long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, cur = 0;
        long long dup = -1;
        unordered_map<int, int> last; // val -> last seen index
        for (int i = 0; i < (int)nums.size(); ++i) {
            cur += nums[i];
            if (i >= k) cur -= nums[i - k];
            if (last.count(nums[i])) dup = max(dup, (long long)last[nums[i]]);
            if (i - dup >= k) res = max(res, cur);
            last[nums[i]] = i;
        }
        return res;
    }
};

#endif
