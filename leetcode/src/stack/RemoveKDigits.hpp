#pragma once
#include <string>

using namespace std;

namespace RemoveKDigits {

class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack; // O(n) space
        for (char c : num) { // O(n)
            while (k > 0 && !stack.empty() && stack.back() > c) { // amortized O(1)
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        stack.resize(stack.size() - k);
        size_t start = stack.find_first_not_of('0');
        return start == string::npos ? "0" : stack.substr(start);
    }
};

} // namespace RemoveKDigits
