#pragma once

#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// O(n) time, O(n) space constructor; O(log n) pickIndex via binary search
class RandomPickWithWeight {
    vector<int> prefix;
    int total;
    mt19937 rng;

public:
    RandomPickWithWeight(vector<int>& w) : rng(random_device{}()) {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < (int)w.size(); i++) {
            prefix[i] = prefix[i - 1] + w[i];
        }
        total = prefix.back();
    }

    int pickIndex() {
        uniform_int_distribution<int> dist(1, total);
        int target = dist(rng);
        // Find first index where prefix[i] >= target
        return lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }
};

// O(n) pickIndex via linear scan
class RandomPickWithWeight2 {
    vector<int> prefix;
    int total;
    mt19937 rng;

public:
    RandomPickWithWeight2(vector<int>& w) : rng(random_device{}()) {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < (int)w.size(); i++) {
            prefix[i] = prefix[i - 1] + w[i];
        }
        total = prefix.back();
    }

    int pickIndex() {
        uniform_int_distribution<int> dist(1, total);
        int target = dist(rng);
        for (int i = 0; i < (int)prefix.size(); i++) {
            if (prefix[i] >= target) return i;
        }
        return (int)prefix.size() - 1;
    }
};
