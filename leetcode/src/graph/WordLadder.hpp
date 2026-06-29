#ifndef LEETCODE_WORDLADDER_HPP
#define LEETCODE_WORDLADDER_HPP

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class WordLadderSolution {
public:
    // BFS with wildcard pattern map
    // Time: O(M^2 * N) where M = word length, N = wordList size
    // Space: O(M^2 * N) for the pattern map
    int ladderLengthBFS(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        int M = beginWord.size();

        // Build wildcard pattern -> list of words mapping
        // O(M * N) patterns, each pattern is M chars -> O(M^2 * N) space
        unordered_map<string, vector<string>> patternMap;
        for (const string& word : wordList) {
            for (int i = 0; i < M; i++) { // O(M) patterns per word
                string pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                patternMap[pattern].push_back(word);
            }
        }

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            // Process all nodes at current level
            for (int s = 0; s < size; s++) { // O(N) nodes total across all levels
                string curr = q.front();
                q.pop();

                for (int i = 0; i < M; i++) { // O(M) patterns per word
                    string pattern = curr.substr(0, i) + "*" + curr.substr(i + 1);
                    for (const string& neighbor : patternMap[pattern]) {
                        if (neighbor == endWord) return level + 1;
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }

    // Bidirectional BFS
    // Time: O(M^2 * N) same worst case but explores fewer nodes in practice
    // Space: O(M^2 * N) for pattern map + visited sets from both ends
    int ladderLengthBidirectional(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        int M = beginWord.size();

        // Build wildcard pattern map - O(M * N) entries
        unordered_map<string, vector<string>> patternMap;
        for (const string& word : wordList) {
            for (int i = 0; i < M; i++) {
                string pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                patternMap[pattern].push_back(word);
            }
        }

        // Two frontiers expanding toward each other
        unordered_set<string> frontBegin, frontEnd;
        unordered_set<string> visitedBegin, visitedEnd;

        frontBegin.insert(beginWord);
        frontEnd.insert(endWord);
        visitedBegin.insert(beginWord);
        visitedEnd.insert(endWord);

        int level = 1;

        while (!frontBegin.empty() && !frontEnd.empty()) {
            // Always expand the smaller frontier - key optimization
            if (frontBegin.size() > frontEnd.size()) {
                swap(frontBegin, frontEnd);
                swap(visitedBegin, visitedEnd);
            }

            unordered_set<string> nextFront;
            for (const string& curr : frontBegin) { // expand smaller side
                for (int i = 0; i < M; i++) { // O(M) patterns
                    string pattern = curr.substr(0, i) + "*" + curr.substr(i + 1);
                    for (const string& neighbor : patternMap[pattern]) {
                        // If the other side already visited this node, we found a path
                        if (visitedEnd.count(neighbor)) return level + 1;
                        if (!visitedBegin.count(neighbor)) {
                            visitedBegin.insert(neighbor);
                            nextFront.insert(neighbor);
                        }
                    }
                }
            }
            frontBegin = nextFront;
            level++;
        }
        return 0;
    }
};

#endif // LEETCODE_WORDLADDER_HPP
