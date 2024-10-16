#ifndef LEET_CODE_ISOMORPHICSTRING_HPP
#define LEET_CODE_ISOMORPHICSTRING_HPP

#include <string>
#include <unordered_map>

using namespace std;

// lc 205
class IsomorphicString {
public:
    bool isIsomorphicMap(string s, string t) { // 12ms, 7.1Mb.
        unordered_map<char, int> map1, map2;
        for (int i = 0; i < s.size(); ++i) {
            if (map1.count(s[i])) {
                if (!map2.count(t[i])) return false;
                else if (map1.at(s[i]) != map2.at(t[i])) return false;
            } else {
                if (map2.count(t[i])) return false;
                else map1[s[i]] = map2[t[i]] = i;
            }
        }
        return true;
    }

    bool isIsomorphicArray1(string s, string t) { // 0ms, 6.9Mb
        short m1[R], m2[R];
        fill_n(m1, R, -1), fill_n(m2, R, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (m1[s[i]] == -1 && m2[t[i]] == -1) {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else if (m1[s[i]] != t[i] || m2[t[i]] != s[i]) return false;
        }
        return true;
    }

    bool isIsomorphicArray2(string s, string t) {
        unsigned short m1[R] = {0}, m2[R] = {0}; // R has to be const for init
        for (int i = 0; i < s.size(); ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = m2[t[i]] = i + 1; // s.length <= 5*10^4, fit in unsigned short, short overflow, still works
        }
        return true;
    }

private:
    const static int R = 128; // c++ 17 can use inline static
};

#endif //LEET_CODE_ISOMORPHICSTRING_HPP
