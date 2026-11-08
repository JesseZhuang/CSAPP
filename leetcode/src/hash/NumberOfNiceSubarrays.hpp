#ifndef NUMBER_OF_NICE_SUBARRAYS_HPP
#define NUMBER_OF_NICE_SUBARRAYS_HPP

#include <vector>
using namespace std;

// LeetCode 1248 - Count Number of Nice Subarrays
class SolutionNumberOfNiceSubarrays {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> prefixCount(nums.size() + 1, 0);
        prefixCount[0] = 1;
        int oddCount = 0, count = 0;
        // One pass: O(n) time, O(n) space for prefix odd-count frequencies.
        for (int num : nums) {
            oddCount += num % 2;
            if (oddCount >= k) count += prefixCount[oddCount - k];
            ++prefixCount[oddCount];
        }
        return count;
    }

    // Exactly k odds = at most k odds - at most k - 1 odds.
    // Two linear passes: O(n) time, O(1) extra space.
    int numberOfSubarraysSliding(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        int left = 0, oddCount = 0, count = 0;
        // Each pointer advances at most n times: O(n) time, O(1) space.
        for (int right = 0; right < (int)nums.size(); ++right) {
            oddCount += nums[right] % 2;
            while (oddCount > k) oddCount -= nums[left++] % 2;
            count += right - left + 1;
        }
        return count;
    }
};

#endif
