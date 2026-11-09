#ifndef SUBARRAYS_WITH_K_DISTINCT_HPP
#define SUBARRAYS_WITH_K_DISTINCT_HPP

#include <vector>
#include <unordered_map>
using namespace std;

// LeetCode 992. Sliding window with atMost(K) - atMost(K - 1).
// O(n) time, O(n) space.
class SubarraysWithKDistinct {
public:
    static int subarraysWithKDistinct(const vector<int>& nums, int k) {
        auto atMost = [&nums](int distinctLimit) {
            if (distinctLimit < 0) return 0LL;

            unordered_map<int, int> freq;
            long long count = 0;
            int left = 0;
            for (int right = 0; right < (int)nums.size(); ++right) {
                if (++freq[nums[right]] == 1) distinctLimit--;
                while (distinctLimit < 0) {
                    if (--freq[nums[left]] == 0) {
                        freq.erase(nums[left]);
                        distinctLimit++;
                    }
                    left++;
                }
                count += right - left + 1;
            }
            return count;
        };

        return (int)(atMost(k) - atMost(k - 1));
    }
};

#endif
