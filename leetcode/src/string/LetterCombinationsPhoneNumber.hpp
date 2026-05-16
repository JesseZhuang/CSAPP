#ifndef LEETCODE_LETTERCOMBINATIONSPHONENUMBER_HPP
#define LEETCODE_LETTERCOMBINATIONSPHONENUMBER_HPP

#include <string>
#include <vector>

using namespace std;

// Solution 1: Iterative BFS-style
// Time: O(4^n * n), Space: O(4^n * n) where n = digits.size()
class Solution17 {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result = {""};
        for (char d : digits) {
            vector<string> next;
            const string &letters = mapping[d - '2'];
            for (const string &prev : result) {
                for (char c : letters) {
                    next.push_back(prev + c);
                }
            }
            result = move(next);
        }
        return result;
    }
};

// Solution 2: Backtracking
// Time: O(4^n * n), Space: O(n) excluding output
class Solution17V2 {
    vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string path;

    void backtrack(const string &digits, int idx) {
        if (idx == (int)digits.size()) {
            result.push_back(path);
            return;
        }
        for (char c : mapping[digits[idx] - '2']) {
            path.push_back(c);
            backtrack(digits, idx + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        result.clear();
        path.clear();
        backtrack(digits, 0);
        return result;
    }
};

#endif //LEETCODE_LETTERCOMBINATIONSPHONENUMBER_HPP
