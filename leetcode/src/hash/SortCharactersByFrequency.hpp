#ifndef SORT_CHARACTERS_BY_FREQUENCY_HPP
#define SORT_CHARACTERS_BY_FREQUENCY_HPP

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/// LeetCode 451, medium, tags: hash table, string, sorting, heap, bucket sort.
class Solution451 {
public:
    /// HashMap + Sort: count frequencies, sort characters by frequency descending.
    /// Time O(n + k log k) where k = unique chars. Space O(n).
    string frequencySortSort(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++; // O(n)
        vector<char> chars;
        for (auto &[c, _] : count) chars.push_back(c);
        sort(chars.begin(), chars.end(), [&](char a, char b) { // O(k log k)
            return count[a] > count[b];
        });
        string result;
        for (char c : chars) result.append(count[c], c); // O(n)
        return result;
    }

    /// Bucket Sort: use frequency as bucket index, iterate from highest bucket.
    /// Time O(n), Space O(n).
    string frequencySortBucket(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++; // O(n)
        int maxFreq = 0;
        for (auto &[_, freq] : count) maxFreq = max(maxFreq, freq); // O(k)
        vector<vector<char>> buckets(maxFreq + 1); // O(n)
        for (auto &[c, freq] : count) buckets[freq].push_back(c); // O(k)
        string result;
        for (int freq = maxFreq; freq > 0; freq--) { // O(n) total
            for (char c : buckets[freq]) result.append(freq, c);
        }
        return result;
    }
};

#endif
