#ifndef LEETCODE_MINIMUMDELETIONSTOMAKESTRINGBALANCED_HPP
#define LEETCODE_MINIMUMDELETIONSTOMAKESTRINGBALANCED_HPP

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution1653 {
public:
    // O(n) time; O(1) extra space. Keep the best result for each prefix.
    int minimumDeletions(const string &s) {
        int bCount = 0;
        int deletions = 0;
        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else {
                // Delete this 'a', or delete all earlier 'b's.
                deletions = min(deletions + 1, bCount);
            }
        }
        return deletions;
    }

    // O(n) time; O(n) extra space for suffix counts of 'a'.
    int minimumDeletionsBySplit(const string &s) {
        const int n = static_cast<int>(s.size());
        vector<int> suffixA(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixA[i] = suffixA[i + 1] + (s[i] == 'a');
        }

        int prefixB = 0;
        int minimum = n;
        for (int split = 0; split <= n; split++) {
            // Keep 'b's before the split and 'a's after it.
            minimum = min(minimum, prefixB + suffixA[split]);
            if (split < n && s[split] == 'b') {
                prefixB++;
            }
        }
        return minimum;
    }
};

#endif // LEETCODE_MINIMUMDELETIONSTOMAKESTRINGBALANCED_HPP
