#ifndef LEETCODE_TOPKFREQUENTELEMENTS_HPP
#define LEETCODE_TOPKFREQUENTELEMENTS_HPP

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// leet 347, bucket sort. O(n) time, O(n) space.
class Solution347Bucket {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums) count[num]++; // O(n)
        int n = (int) nums.size();
        vector<vector<int>> buckets(n + 1); // index = frequency
        for (auto &[num, freq]: count) buckets[freq].push_back(num); // O(n) distribute
        vector<int> res;
        for (int freq = n; freq > 0 && (int) res.size() < k; freq--) { // O(n) collect
            for (int num: buckets[freq]) {
                res.push_back(num);
                if ((int) res.size() == k) return res;
            }
        }
        return res;
    }
};

// leet 347, min-heap of size k. O(n log k) time, O(n) space.
class Solution347Heap {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums) count[num]++; // O(n)
        // min-heap by frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto &[num, freq]: count) { // O(n log k)
            pq.emplace(freq, num);
            if ((int) pq.size() > k) pq.pop(); // evict least frequent
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

#endif //LEETCODE_TOPKFREQUENTELEMENTS_HPP
