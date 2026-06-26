#ifndef LEETCODE_OPENTHELOCK_HPP
#define LEETCODE_OPENTHELOCK_HPP

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// LeetCode 752 - Open the Lock
// BFS from "0000" to target, avoiding deadends
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        unordered_set<string> visited;
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        int steps = 0;

        while (!q.empty()) {
            ++steps;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string cur = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    for (int d : {1, -1}) {
                        string next = cur;
                        next[j] = (cur[j] - '0' + d + 10) % 10 + '0';
                        if (next == target) return steps;
                        if (!dead.count(next) && !visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

// Bidirectional BFS: expand from both sides, meet in the middle
class SolutionBidirectional {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        unordered_set<string> front, back, visited;
        front.insert("0000");
        back.insert(target);
        visited.insert("0000");
        visited.insert(target);
        int steps = 0;

        while (!front.empty() && !back.empty()) {
            ++steps;
            // Always expand the smaller frontier
            if (front.size() > back.size()) swap(front, back);

            unordered_set<string> nextFront;
            for (const string& cur : front) {
                for (int j = 0; j < 4; ++j) {
                    for (int d : {1, -1}) {
                        string next = cur;
                        next[j] = (cur[j] - '0' + d + 10) % 10 + '0';
                        if (back.count(next)) return steps;
                        if (!dead.count(next) && !visited.count(next)) {
                            visited.insert(next);
                            nextFront.insert(next);
                        }
                    }
                }
            }
            front = std::move(nextFront);
        }
        return -1;
    }
};

#endif //LEETCODE_OPENTHELOCK_HPP
