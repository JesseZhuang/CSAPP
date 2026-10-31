#pragma once
#include <string>

namespace CheckIfWordIsValidAfterSubstitutions {

class Solution {
public:
    // Each character is pushed once and removed at most once: O(n) time,
    // O(n) auxiliary space for the unreduced prefix.
    bool isValid(std::string s) {
        std::string pending;
        pending.reserve(s.size());
        for (char ch : s) {
            pending.push_back(ch);
            const auto size = pending.size();
            if (size >= 3 && pending[size - 3] == 'a' &&
                pending[size - 2] == 'b' && pending[size - 1] == 'c') {
                pending.resize(size - 3);
            }
        }
        return pending.empty();
    }
};

}
