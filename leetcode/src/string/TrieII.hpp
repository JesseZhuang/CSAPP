#ifndef LEETCODE_TRIEII_HPP
#define LEETCODE_TRIEII_HPP

#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

// leet 1804, O(n) time and space per operation.
class TrieII {
    unordered_map<char, unique_ptr<TrieII>> next;
    int wordCount = 0;
    int prefixCount = 0;

public:
    TrieII() = default;

    void insert(const string &word) {
        TrieII *cur = this;
        for (char c: word) {
            if (!cur->next.count(c)) cur->next[c] = make_unique<TrieII>();
            cur = cur->next[c].get();
            cur->prefixCount++;
        }
        cur->wordCount++;
    }

    int countWordsEqualTo(const string &word) {
        auto *node = get(word);
        return node ? node->wordCount : 0;
    }

    int countWordsStartingWith(const string &prefix) {
        auto *node = get(prefix);
        return node ? node->prefixCount : 0;
    }

    void erase(const string &word) {
        TrieII *cur = this;
        for (char c: word) {
            cur = cur->next[c].get();
            cur->prefixCount--;
        }
        cur->wordCount--;
    }

private:
    TrieII *get(const string &word) {
        TrieII *cur = this;
        for (char c: word) {
            if (!cur->next.count(c)) return nullptr;
            cur = cur->next[c].get();
        }
        return cur;
    }
};

#endif //LEETCODE_TRIEII_HPP
