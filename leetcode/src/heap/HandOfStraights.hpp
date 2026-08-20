#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

// lc 846 - Hand of Straights
// Greedy with ordered map: O(n log n) time, O(n) space.
class Solution846 {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for (int c : hand) count[c]++;
        while (!count.empty()) {
            int start = count.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                if (count.find(card) == count.end()) return false;
                if (--count[card] == 0) count.erase(card);
            }
        }
        return true;
    }
};

// Sort + hash map: O(n log n) time, O(n) space.
class Solution846V2 {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> count;
        for (int c : hand) count[c]++;
        for (int c : hand) {
            if (count[c] == 0) continue;
            for (int i = 0; i < groupSize; i++) {
                int card = c + i;
                if (count[card] <= 0) return false;
                count[card]--;
            }
        }
        return true;
    }
};
