#ifndef LRU_CACHE_HPP
#define LRU_CACHE_HPP

#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

/// LeetCode 146 / LintCode 134, medium, tags: hash table, doubly-linked list, design.
///
/// O(1) get and put using a hash map keyed on `key` whose value is an iterator
/// into a doubly-linked list of (key, value) pairs ordered MRU at the front.
class LRUCacheCpp {
    int cap;
    list<pair<int, int>> ll;                                  // front = MRU, back = LRU
    unordered_map<int, list<pair<int, int>>::iterator> map;   // key -> node iterator

public:
    explicit LRUCacheCpp(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        // Move accessed node to the front in O(1) using std::list::splice.
        ll.splice(ll.begin(), ll, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            it->second->second = value;
            ll.splice(ll.begin(), ll, it->second);
            return;
        }
        if ((int)ll.size() == cap) {                          // evict LRU
            map.erase(ll.back().first);
            ll.pop_back();
        }
        ll.emplace_front(key, value);
        map[key] = ll.begin();
    }
};

#endif
