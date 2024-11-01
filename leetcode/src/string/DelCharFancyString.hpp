#ifndef CPP_DELCHARFANCYSTRING_HPP
#define CPP_DELCHARFANCYSTRING_HPP

#include <string>

using namespace std;

class Solution {
public:
    [[maybe_unused]] string makeFancyString(string s) {
        size_t j = 2;
        for (size_t i = 2; i < s.size(); i++) {
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
                s[j++] = s[i];
        }
        s.resize(min(j, s.size()));
        return s;
    }
};

#endif //CPP_DELCHARFANCYSTRING_HPP
