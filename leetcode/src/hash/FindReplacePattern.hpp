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
    bool match(string &word, const string &pattern) {
        unordered_map<char, char> llm;
        for (size_t i = 0; i < word.length(); i++) {
            auto [fst, snd] = llm.emplace(word[i], pattern[i]);
            if (!snd && (*fst).second != pattern[i]) return false;
        }
        auto v = views::values(llm);
        set<char> uniq{v.begin(), v.end()};
        return llm.size() == uniq.size();
    }

    vector<string> findAndReplacePattern(vector<string> &words, const string &pattern) {
        return ranges::to<vector<string> >(
                words | views::filter([&](string &w) { return match(w, pattern); }));
    }
};


#endif //FINDREPLACEPATTERN_HPP
