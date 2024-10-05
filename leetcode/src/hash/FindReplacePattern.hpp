#ifndef FINDREPLACEPATTERN_HPP
#define FINDREPLACEPATTERN_HPP

#include <set>
#include <string>
#include <unordered_map>
#include <ranges>
#include <vector>

using namespace std;


class Solution {
public:
    bool match(string &word, string pattern) {
        unordered_map<char, char> llm;
        for (size_t i = 0; i < word.length(); i++) {
            auto ret = llm.emplace(word[i], pattern[i]);
            if (!ret.second && (*ret.first).second != pattern[i]) return false;
        }
        auto kv = views::values(llm);
        set<char> uniq{kv.begin(), kv.end()};
        return llm.size() == uniq.size();
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        return ranges::to<vector<string> >(
            words | views::filter([this, pattern](string &w) { return match(w, pattern); }));
    }
};


#endif //FINDREPLACEPATTERN_HPP
