#ifndef TRIENODE_HPP
#define TRIENODE_HPP

#include <array>

using namespace std;

constexpr static int A = 'a';
constexpr static int Z = 'z';
constexpr static int TWENTY_SIX = Z - A + 1;

// credit vysbor@
class TrieNode {
public:
    array<unique_ptr<TrieNode>, TWENTY_SIX> next{nullptr};
    bool isWord = false;
    unsigned int cnt = 0;

    TrieNode() = default;

    void insert(const string &word) {
        auto *node = this;
        for (auto &ch: word) {
            const int id = ch - A;
            if (!node->next[id]) node->next[id] = make_unique<TrieNode>();
            node = node->next[id].get();
            node->cnt++;
        }
        node->isWord = true;
    }

    TrieNode *get(const string &word) {
        TrieNode *node = this;
        for (int i = 0; i < word.length(); ++i) {
            const int id = word[i] - A;
            if (!node->next[id]) return nullptr;
            node = node->next[id].get();
        }
        return node;
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


#endif //TRIENODE_HPP
