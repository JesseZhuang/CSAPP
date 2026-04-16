#ifndef GROUP_ANAGRAMS_HPP
#define GROUP_ANAGRAMS_HPP

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/// LeetCode 49, medium, tags: array, hash table, string, sorting.
class Solution49 {
public:
    /// Sort each string to form a canonical key, group by that key.
    /// Time O(n * k log k), Space O(n * k).
    vector<vector<string>> groupAnagramsSort(vector<string> &strs) {
        unordered_map<string, vector<string>> groups;
        for (auto &s : strs) { // O(n)
            string key = s;
            sort(key.begin(), key.end()); // O(k log k)
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &[k, v] : groups) result.push_back(v);
        return result;
    }

    /// Use character frequency count as key to avoid sorting.
    /// Time O(n * k), Space O(n * k).
    vector<vector<string>> groupAnagramsCount(vector<string> &strs) {
        unordered_map<string, vector<string>> groups;
        for (auto &s : strs) { // O(n)
            string key(26, '0');
            for (char c : s) key[c - 'a']++; // O(k)
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &[k, v] : groups) result.push_back(v);
        return result;
    }
};

#endif
