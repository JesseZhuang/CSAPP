#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Sort + Binary Search (lower_bound).
    // O(n log n + m*L*log n) time, O(sort) space.
    // n = products.size(), m = searchWord.size(), L = max product length.
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string prefix;

        for (char c : searchWord) {
            prefix += c;
            // Find first product >= prefix
            auto it = lower_bound(products.begin(), products.end(), prefix);
            vector<string> suggestions;
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                const string& s = *(it + i);
                // Check if s starts with prefix
                if (s.substr(0, prefix.size()) == prefix) {
                    suggestions.push_back(s);
                } else {
                    break;
                }
            }
            result.push_back(std::move(suggestions));
        }
        return result;
    }
};
