#ifndef LEETCODE_ADDSEARCHWORD_HPP
#define LEETCODE_ADDSEARCHWORD_HPP

#include <string>

using namespace std;

// LeetCode 211 - Design Add and Search Words Data Structure
// Trie that supports '.' wildcard matching any single character.

class WordDictionary {
    struct WDTrieNode {
        WDTrieNode* children[26]{};
        bool isEnd = false;

        ~WDTrieNode() {
            for (auto& child : children)
                delete child;
        }
    };

    WDTrieNode* root;

    bool dfs(WDTrieNode* node, const string& word, int pos) {
        if (!node) return false;
        if (pos == (int)word.size()) return node->isEnd;

        char c = word[pos];
        if (c == '.') {
            for (auto& child : node->children) {
                if (dfs(child, word, pos + 1))
                    return true;
            }
            return false;
        }
        return dfs(node->children[c - 'a'], word, pos + 1);
    }

public:
    WordDictionary() : root(new WDTrieNode()) {}
    ~WordDictionary() { delete root; }

    // Time O(m) where m = word.length()
    // Space O(m) — new nodes along the path
    void addWord(const string& word) {
        WDTrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new WDTrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // Time O(26^d * m) worst case where d = number of dots, m = word.length()
    //   For words with no dots: O(m)
    // Space O(m) — recursion depth
    bool search(const string& word) {
        return dfs(root, word, 0);
    }
};

#endif //LEETCODE_ADDSEARCHWORD_HPP
