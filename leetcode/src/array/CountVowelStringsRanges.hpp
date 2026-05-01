#pragma once
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// leet 2559, prefix sum, O(n+m) time, O(m) space
class SolutionCountVowelStringsRanges {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size(), s = 0, m = queries.size();
        vector<int> psa(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (vowels.count(words[i].front()) && vowels.count(words[i].back())) s++;
            psa[i + 1] = s;
        }
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = psa[queries[i][1] + 1] - psa[queries[i][0]];
        }
        return res;
    }
};
