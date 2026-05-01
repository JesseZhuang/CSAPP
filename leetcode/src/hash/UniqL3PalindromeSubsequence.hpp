#ifndef LEETCODE_UNIQL3PALINDROMESUBSEQUENCE_HPP
#define LEETCODE_UNIQL3PALINDROMESUBSEQUENCE_HPP

#include <string>
#include <unordered_set>
#include <climits>

using namespace std;

// leet 1930
class SolutionUniqL3Palindrome {
public:
    int countPalindromicSubsequence(const string &s) {
        int first[26], last[26];
        fill(first, first + 26, INT_MAX);
        fill(last, last + 26, 0);
        for (int i = 0; i < (int) s.size(); ++i) {
            int id = s[i] - 'a';
            first[id] = min(first[id], i);
            last[id] = i;
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (first[i] < last[i]) {
                unordered_set<char> between;
                for (int j = first[i] + 1; j < last[i]; ++j)
                    between.insert(s[j]);
                res += (int) between.size();
            }
        }
        return res;
    }
};

#endif //LEETCODE_UNIQL3PALINDROMESUBSEQUENCE_HPP
