#ifndef MAXFREQSTACK_HPP
#define MAXFREQSTACK_HPP

#include <unordered_map>
#include <vector>

// LeetCode 895 - Maximum Frequency Stack
// Time:  O(1) push, O(1) pop
// Space: O(n)
class FreqStack895 {
public:
    void push(int val) {
        int f = ++freq[val];
        group[f].push_back(val);
        if (f > maxFreq) maxFreq = f;
    }

    int pop() {
        int val = group[maxFreq].back();
        group[maxFreq].pop_back();
        freq[val]--;
        if (group[maxFreq].empty()) maxFreq--;
        return val;
    }

private:
    std::unordered_map<int, int> freq;
    std::unordered_map<int, std::vector<int>> group;
    int maxFreq = 0;
};

#endif
