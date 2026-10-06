#pragma once

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxKelements(const vector<int>& numbers, int operationCount) {
        priority_queue<int> maxHeap(numbers.begin(), numbers.end());
        long long score = 0;

        for (int operation = 0; operation < operationCount; ++operation) {
            const int maximum = maxHeap.top();
            score += maximum;
            maxHeap.pop();
            maxHeap.push((maximum + 2) / 3);
        }

        return score;
    }
};
