#ifndef CONSTRUCT_DISTANCED_SEQUENCE_HPP
#define CONSTRUCT_DISTANCED_SEQUENCE_HPP

#include <vector>

using namespace std;

// LeetCode 1718. Construct the Lexicographically Largest Valid Sequence.
class ConstructDistancedSequence {
public:
    static vector<int> constructDistancedSequence(int n) {
        vector<int> sequence(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        search(0, n, sequence, used);
        return sequence;
    }

private:
    static bool search(int index, int n, vector<int>& sequence, vector<bool>& used) {
        while (index < (int)sequence.size() && sequence[index] != 0) ++index;
        if (index == (int)sequence.size()) return true;

        // O(n * n!) worst-case time, O(n) auxiliary space. Descending choices at
        // the leftmost empty slot make the first solution lexicographically largest.
        for (int value = n; value >= 1; --value) {
            if (used[value]) continue;
            const int second = value == 1 ? index : index + value;
            if (second >= (int)sequence.size() || sequence[second] != 0) continue;

            sequence[index] = sequence[second] = value;
            used[value] = true;
            if (search(index + 1, n, sequence, used)) return true;
            used[value] = false;
            sequence[index] = sequence[second] = 0;
        }
        return false;
    }
};

#endif
