#ifndef TRIENODE_HPP
#define TRIENODE_HPP
#include <array>

using namespace std;

constexpr static int A = 'a';
constexpr static int Z = 'z';
constexpr static int TWENTY_SIX = Z - A + 1;

class TrieNode {
public:
    array<unique_ptr<TrieNode>, TWENTY_SIX> next{nullptr};
    bool isWord = false;

    TrieNode() = default;
};


#endif //TRIENODE_HPP
