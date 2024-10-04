#ifndef TRIEP_HPP
#define TRIEP_HPP
#include <string>

using namespace std;

// use raw pointer and free memory to avoid leak
class Node {
public:
    bool isWord;
    Node **next; // pointer to array of pointers, double pointer

    Node() {
        next = new Node *[26]();
        isWord = false;
    }

    // free memory to avoid leak
    ~Node() {
        for (int i = 0; i < 26; i++)
            delete next[i]; // delete nullptr is safe, a no-op.
        delete[] next;
    }
};

class TrieP {
public:
    TrieP() {
        root = new Node();
    }

    void insert(string word) {
        // pass by value, avoid copy
        getNode(move(word), true)->isWord = true;
    }

    bool search(string word) {
        Node *n = getNode(word, false);
        return n != nullptr && n->isWord;
    }

    bool startsWith(string prefix) {
        return getNode(prefix, false) != nullptr;
    }

private:
    Node *root;

    Node *getNode(string word, bool create) {
        Node *cur = root;
        int id;
        size_t n = word.size();
        for (size_t i = 0; i < n; ++i) {
            id = word[i] - 'a';
            if (cur->next[id] == nullptr) {
                if (create) cur->next[id] = new Node();
                else return nullptr;
            }
            cur = cur->next[id];
        }
        return cur;
    }
};


#endif //TRIEP_HPP
