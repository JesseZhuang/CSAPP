#ifndef TIME_BASED_KEY_VALUE_STORE_HPP
#define TIME_BASED_KEY_VALUE_STORE_HPP

#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/// LeetCode 981, medium, tags: hash table, string, binary search, design.

/// Solution 1: unordered_map + vector + upper_bound (binary search).
/// Timestamps are strictly increasing per key, so vector stays sorted.
/// Time: set O(1), get O(log n). Space: O(n) total entries.
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";
        auto &vec = it->second;
        // upper_bound finds first element with timestamp > given timestamp
        auto ub = upper_bound(vec.begin(), vec.end(), make_pair(timestamp, string(127, '\x7f')));
        if (ub == vec.begin()) return "";
        return prev(ub)->second;
    }
};

/// Solution 2: unordered_map + ordered map.
/// Time: set O(log n), get O(log n). Space: O(n) total entries.
class TimeMap2 {
    unordered_map<string, map<int, string>> store;

public:
    TimeMap2() {}

    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";
        auto &m = it->second;
        // upper_bound finds first key > timestamp, go back one
        auto ub = m.upper_bound(timestamp);
        if (ub == m.begin()) return "";
        return prev(ub)->second;
    }
};

#endif
