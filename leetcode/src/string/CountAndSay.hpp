#ifndef COUNT_AND_SAY_HPP
#define COUNT_AND_SAY_HPP

#include <string>

using namespace std;

/// LeetCode 38, medium, tags: math, string, simulation.
class SolutionCountAndSay {
public:
    /// Iteratively build run-length encoded terms. Time O(1.3^n), Space O(1.3^n).
    string countAndSay(int n) {
        string res = "1";
        for (int round = 1; round < n; ++round) {
            string nxt;
            int i = 0, m = (int)res.size();
            while (i < m) {                     // O(|res|) per round
                int count = 1;
                while (i + 1 < m && res[i] == res[i + 1]) { ++count; ++i; }
                nxt += to_string(count);
                nxt += res[i];
                ++i;
            }
            res = std::move(nxt);
        }
        return res;
    }
};

#endif
