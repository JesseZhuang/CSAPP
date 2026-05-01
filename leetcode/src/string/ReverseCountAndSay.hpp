#ifndef REVERSE_COUNT_AND_SAY_HPP
#define REVERSE_COUNT_AND_SAY_HPP

#include <stdexcept>
#include <string>

using namespace std;

/// Reverse of LeetCode 38 follow-up. Tags: math, string, simulation.
class SolutionReverseCountAndSay {
public:
    /// Expand RLE pairs (count, digit) back to the previous Count-and-Say term.
    /// Time O(n), Space O(n) for the output buffer.
    string reverseCountSay(const string& s) {
        if (s.empty()) return "";
        if (s.size() % 2 != 0) throw invalid_argument("odd length input");
        string out;
        for (size_t i = 0; i < s.size(); i += 2) {
            char countCh = s[i];
            if (countCh < '0' || countCh > '9') throw invalid_argument("non-digit count");
            int cnt = countCh - '0';
            out.append(cnt, s[i + 1]);
        }
        return out;
    }
};

#endif
