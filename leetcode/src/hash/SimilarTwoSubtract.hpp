#ifndef SIMILAR_TWO_SUBTRACT_HPP
#define SIMILAR_TWO_SUBTRACT_HPP

#include <unordered_map>
#include <vector>

using namespace std;

/// LeetCode 1 similar (Salesforce variant), medium, tags: array, hash table.
///
/// Given array A and target T, return the number of ordered pairs (i, j) where
/// A[i] - A[j] == T. Duplicates are counted with multiplicity.
class SolutionSimilarTwoSubtract {
public:
    /// Count pairs whose difference equals target.
    /// Time O(n), Space O(n).
    int twoSubtract(const vector<int>& A, int target) {
        unordered_map<int, int> cnt;
        for (int v : A) cnt[v]++;            // O(n)
        int res = 0;
        for (const auto& [v, c] : cnt) {     // O(unique) ≤ O(n)
            auto it = cnt.find(v + target);  // look forward to avoid double counting
            if (it != cnt.end()) res += c * it->second;
        }
        return res;
    }
};

#endif
