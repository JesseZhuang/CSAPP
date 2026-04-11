#ifndef LEETCODE_KTHLARGESTELEMENT_HPP
#define LEETCODE_KTHLARGESTELEMENT_HPP

#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

// leet 215
class Solution215Heap {
public:
    // Time O(n log k), Space O(k)
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq; // min-heap of size k
        for (int n : nums) {
            pq.push(n);
            if ((int)pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

class Solution215Quickselect {
public:
    // Time O(n) average, O(n^2) worst, Space O(1)
    int findKthLargest(vector<int> &nums, int k) {
        int target = (int)nums.size() - k; // kth largest = (n-k)th smallest
        return quickselect(nums, 0, (int)nums.size() - 1, target);
    }

private:
    int quickselect(vector<int> &nums, int lo, int hi, int target) {
        while (lo < hi) {
            int pivotIdx = lo + rand() % (hi - lo + 1); // random pivot
            swap(nums[pivotIdx], nums[hi]);
            int pivot = nums[hi];
            int store = lo;
            for (int i = lo; i < hi; i++) {
                if (nums[i] <= pivot)
                    swap(nums[i], nums[store++]);
            }
            swap(nums[store], nums[hi]);
            if (store == target)
                return nums[store];
            else if (store < target)
                lo = store + 1;
            else
                hi = store - 1;
        }
        return nums[lo];
    }
};

#endif //LEETCODE_KTHLARGESTELEMENT_HPP
