#ifndef TRIEP_HPP
#define TRIEP_HPP

#include <string>
#include <utility>

using namespace std;

// use raw pointer and free memory to avoid leak, credit: ohini@
class Node {
public:
    bool end;
    Node **next; // pointer to array of pointers, double pointer

    Node() {
        next = new Node *[26]();
        end = false;
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
        getNode(std::move(word), true)->end = true;
    }

    bool search(string word) {
        Node *n = getNode(std::move(word), false);
        return n != nullptr && n->end;
    }

    bool startsWith(string prefix) {
        return getNode(std::move(prefix), false) != nullptr;
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
