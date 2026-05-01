#ifndef LEETCODE_DESIGNFILESYSTEM_HPP
#define LEETCODE_DESIGNFILESYSTEM_HPP

#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

// leet 1166
class FileSystem {
    struct TrieNode {
        unordered_map<string, TrieNode*> next;
        int val = -1;
    };
    TrieNode root;

    static vector<string> split(const string &path) {
        vector<string> parts;
        istringstream ss(path);
        string token;
        while (getline(ss, token, '/'))
            if (!token.empty()) parts.push_back(token);
        return parts;
    }

public:
    bool createPath(const string &path, int value) {
        auto ps = split(path);
        TrieNode *node = &root;
        for (int i = 0; i < (int)ps.size() - 1; i++) {
            if (node->next.find(ps[i]) == node->next.end()) return false;
            node = node->next[ps[i]];
        }
        if (node->next.find(ps.back()) != node->next.end()) return false;
        auto *newNode = new TrieNode();
        newNode->val = value;
        node->next[ps.back()] = newNode;
        return true;
    }

    int get(const string &path) {
        auto ps = split(path);
        TrieNode *node = &root;
        for (auto &p : ps) {
            if (node->next.find(p) == node->next.end()) return -1;
            node = node->next[p];
        }
        return node->val;
    }
};

#endif //LEETCODE_DESIGNFILESYSTEM_HPP
