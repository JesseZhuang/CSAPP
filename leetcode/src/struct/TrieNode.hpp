#ifndef TRIENODE_HPP
#define TRIENODE_HPP

#include <array>
#include <memory> // unique_ptr

using namespace std;

//constexpr since c++ 11, https://www.geeksforgeeks.org/understanding-constexper-specifier-in-cpp/
//constexpr static int A = 'a';
//constexpr static int Z = 'z';
//constexpr static int TWENTY_SIX = Z - A + 1;

// credit vysbor@
class TrieNode {
public:
    unordered_map<char, unique_ptr<TrieNode>> next; // not unique_pointer
//    array<unique_ptr<TrieNode>, TWENTY_SIX> next{nullptr};
    bool end = false;
    unsigned int cnt = 0;

    TrieNode() = default;

    void insert(const string &word) {
        auto *node = this;
        for (auto &ch: word) {
            if (!node->next.count(ch)) node->next[ch] = make_unique<TrieNode>();
            node = node->next[ch].get();
            node->cnt++;
        }
        node->end = true;
    }

    TrieNode *get(const string &word) {
        TrieNode *node = this;
        for (auto &ch: word) {
            if (!node->next.count(ch)) return nullptr;
            node = node->next[ch].get();
        }
        return node;
    }

    bool search(const string &word) {
        auto *node = get(word);
        return node != nullptr && node->end;
    }

    bool startsWith(const string &word) {
        auto *node = get(word);
        return node != nullptr;
    }

    int lcpLen(const string &w) {
        int res = 0;
        auto cur = this;
        for (auto &c: w) {
            if (!cur->next.count(c)) break;
            cur = cur->next[c].get();
            res++;
        }
        return res;
    }
};


#endif //TRIENODE_HPP
