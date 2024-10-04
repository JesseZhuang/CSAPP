#ifndef TRIE_HPP
#define TRIE_HPP
#include <string>

#include "TrieNode.hpp"

using namespace std;

// LeetCode 208
class Trie {
    unique_ptr<TrieNode> root = make_unique<TrieNode>();

public:
    Trie() = default;

private:
    TrieNode *get(const string &word) {
        auto *node = root.get();
        for (int i = 0; i < word.length(); ++i) {
            const int id = word[i] - A;
            if (!node->next[id]) return nullptr;
            node = node->next[id].get();
        }
        return node;
    }

public:
    void insert(const string &word) {
        auto *node = root.get();
        for (int i = 0; i < word.length(); ++i) {
            const int id = word[i] - A;
            if (!node->next[id]) node->next[id] = make_unique<TrieNode>();
            node = node->next[id].get();
        }
        node->isWord = true;
    }

    bool search(const string &word) {
        auto *node = get(word);
        return node != nullptr && node->isWord;
    }

    bool startsWith(const string &word) {
        auto *node = get(word);
        return node != nullptr;
    }
};


#endif //TRIE_HPP
