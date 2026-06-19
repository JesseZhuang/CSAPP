#pragma once
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

// leet 2542, sort by nums2 desc, min-heap of size k on nums1 values.
// O(n log n) time, O(n) space.
class SolutionMaximumSubsequenceScore {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums2[a] > nums2[b];
        });

        priority_queue<int, vector<int>, greater<>> pq; // min-heap
        long long sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int j = idx[i];
            sum += nums1[j];
            pq.push(nums1[j]);
            if ((int)pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() == k) {
                ans = max(ans, sum * nums2[j]);
            }
        }
        return ans;
    }
};
