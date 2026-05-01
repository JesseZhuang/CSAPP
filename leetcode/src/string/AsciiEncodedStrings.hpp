#ifndef ASCII_ENCODED_STRINGS_HPP
#define ASCII_ENCODED_STRINGS_HPP

#include <algorithm>
#include <string>

using namespace std;

/// HackerRank ASCII Encoded Strings (Goldman Sachs, Salesforce, VMware variant).
/// related to LeetCode 91, LintCode 512.
///
/// The encoding reverses the concatenation of ASCII decimal codes; assuming the
/// alphabet is `[A-Za-z]` and space (codes 32, 65-90, 97-122), then in the
/// reversed string a digit '3'..'9' starts a 2-digit code, and '1' or '2'
/// starts a 3-digit code.
class SolutionAsciiEncodedStrings {
public:
    string encode(const string& s) {
        string out;
        for (char c : s) out += to_string((int)(unsigned char)c);
        std::reverse(out.begin(), out.end());
        return out;
    }

    string decode(const string& encoded) {
        string s = encoded;
        std::reverse(s.begin(), s.end());
        string res;
        size_t i = 0, n = s.size();
        while (i < n) {
            if (s[i] >= '3' && s[i] <= '9') {       // 2-digit code (32..99)
                res.push_back((char)stoi(s.substr(i, 2)));
                i += 2;
            } else {                                  // 3-digit code (100..126)
                res.push_back((char)stoi(s.substr(i, 3)));
                i += 3;
            }
        }
        return res;
    }
};

#endif
