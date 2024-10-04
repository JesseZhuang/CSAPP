#include <unordered_map>
#include "ValidAnagram.hpp"

using namespace std;

// 4ms, 7.2Mb.
bool ValidAnagram::isAnagram(string s, string t) {
    if (s.size() != t.size()) return false; // size length same, length from c
    unordered_map<char, int> counts;
    for (size_t i = 0; i < s.size(); i++) {
        counts[s[i]]++;
        counts[t[i]]--; // not s again, use t
    }
    for (auto count: counts) if (count.second != 0) return false;
    return true;
}

// 4ms, 7.4Mb.
bool ValidAnagram::isAnagramArray(string s, string t) {
    if (s.size() != t.size()) return false;
    int counts[26] = {}; // default init to 0
    for (int i = 0; i < s.size(); ++i) {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
    }
    for (auto count: counts) if (count != 0) return false;
    return true;
}
