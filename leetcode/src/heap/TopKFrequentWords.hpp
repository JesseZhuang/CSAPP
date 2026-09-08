#ifndef LEETCODE_TOPKFREQUENTWORDS_HPP
#define LEETCODE_TOPKFREQUENTWORDS_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// leet 692, min-heap approach. O(n log k) time, O(n) space.
class Solution692Heap {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> count;
        for (auto &w : words) count[w]++; // O(n) frequency count

        // Min-heap comparator: lower freq on top; for same freq, reverse lex (higher lex on top)
        // so the element we'd evict first is the least desirable to keep.
        auto cmp = [](const pair<int, string> &a, const pair<int, string> &b) {
            if (a.first != b.first) return a.first > b.first; // higher freq = higher priority (stays)
            return a.second < b.second;                        // lower lex = higher priority (stays)
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for (auto &[word, freq] : count) { // O(n log k) heap maintenance
            pq.emplace(freq, word);
            if ((int) pq.size() > k) pq.pop(); // evict least important
        }

        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) { // O(k log k) pop in reverse order
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};

// leet 692, bucket sort. O(n + m log m) time where m = unique words, O(n) space.
class Solution692Bucket {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> count;
        for (auto &w : words) count[w]++; // O(n) frequency count

        int n = (int) words.size();
        vector<vector<string>> buckets(n + 1); // index = frequency, O(n) space
        for (auto &[word, freq] : count) buckets[freq].push_back(word); // O(m) distribute

        vector<string> res;
        for (int freq = n; freq > 0 && (int) res.size() < k; freq--) {
            sort(buckets[freq].begin(), buckets[freq].end()); // O(b log b) lex sort per bucket
            for (auto &w : buckets[freq]) {
                res.push_back(w);
                if ((int) res.size() == k) return res;
            }
        }
        return res;
    }
};

#endif //LEETCODE_TOPKFREQUENTWORDS_HPP
