#ifndef TRIE_HPP
#define TRIE_HPP

#include "struct/TrieNode.hpp"

using namespace std;

// LeetCode 208
class Trie {
    unique_ptr<TrieNode> root = make_unique<TrieNode>();

public:
    Trie() = default;

    void insert(const string &word) {
        root->insert(word);
    }

    bool search(const string &word) {
        return root->search(word);
    }

    bool startsWith(const string &word) {
        return root->startsWith(word);
    }
};


#endif //TRIE_HPP
