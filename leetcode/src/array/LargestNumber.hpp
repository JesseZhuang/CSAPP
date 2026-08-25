#ifndef LARGESTNUMBER_HPP
#define LARGESTNUMBER_HPP
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator: for strings a, b compare (a+b) vs (b+a). O(n log n) time.
class Solution179 {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        strs.reserve(nums.size());
        for (int n : nums) strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (strs[0] == "0") return "0"; // all zeros
        string res;
        for (auto& s : strs) res += s;
        return res;
    }
};

#endif
