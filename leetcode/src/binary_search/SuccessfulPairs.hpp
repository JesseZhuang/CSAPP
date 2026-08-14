#pragma once

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Sort potions + Binary Search for each spell.
    // O((m+n) log n) time, O(n) extra space for sorting.
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> result;
        result.reserve(spells.size());

        for (int spell : spells) {
            // Find minimum potion value such that spell * potion >= success
            // i.e. potion >= ceil(success / spell)
            long long minPotion = (success + spell - 1) / spell;  // ceiling division

            // lower_bound finds first element >= minPotion
            // If minPotion exceeds max possible potion value (10^5), all fail
            if (minPotion > 100000) { result.push_back(0); continue; }
            int idx = lower_bound(potions.begin(), potions.end(), (int)minPotion) - potions.begin();
            result.push_back(n - idx);
        }
        return result;
    }
};
