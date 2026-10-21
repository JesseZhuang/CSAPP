#pragma once
#include <cstddef>
#include <stack>
#include <vector>

using namespace std;

namespace ValidateStackSequences {

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> pending;
        size_t poppedIndex = 0;
        for (int value : pushed) {
            pending.push(value);
            // Amortized O(n): the inner loop pops each element at most once.
            while (!pending.empty() && poppedIndex < popped.size() && pending.top() == popped[poppedIndex]) {
                pending.pop();
                ++poppedIndex;
            }
        }
        return poppedIndex == popped.size();
    }
};

}
