#pragma once
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

// leet 1438, monotonic deques, O(n) time, O(n) space
class SolutionLongestSubarrayAbsDiffLimit {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxQ, minQ; // O(n) space for both deques
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            // Maintain decreasing deque for max — O(1) amortized per element
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[r])
                maxQ.pop_back();
            maxQ.push_back(r);
            // Maintain increasing deque for min — O(1) amortized per element
            while (!minQ.empty() && nums[minQ.back()] >= nums[r])
                minQ.pop_back();
            minQ.push_back(r);
            // Shrink window until abs diff <= limit
            while (nums[maxQ.front()] - nums[minQ.front()] > limit) {
                l++;
                if (maxQ.front() < l) maxQ.pop_front();
                if (minQ.front() < l) minQ.pop_front();
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// leet 1438, multiset, O(n log n) time, O(n) space
class SolutionLongestSubarrayAbsDiffLimit2 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> window; // O(n) space, maintains sorted order
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            window.insert(nums[r]); // O(log n) insertion
            // Shrink window until max - min <= limit
            while (*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[l])); // O(log n) erasure
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
