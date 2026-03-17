#ifndef LEETCODE_FINDUNIQUEBINARYSTRING_HPP
#define LEETCODE_FINDUNIQUEBINARYSTRING_HPP

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // 0ms 12.75mb
    string findDifferentBinaryString(const vector<string> &nums) {
        int n = static_cast<int>(nums.size());
        string ans(n, '0');
        for (int i = 0; i < n; i++) {
            char c = nums[i][i];
            ans[i] = (c == '0') ? '1' : '0';
        }
        return ans;
    }

    // 0ms 12.83mb
    string findDifferentBinaryStringSet(const vector<string> &nums) {
        int n = static_cast<int>(nums.size());
        unordered_set < string > seen(nums.begin(), nums.end());
        int total = 1 << n;
        for (int mask = 0; mask < total; mask++) {
            string candidate(n, '0');
            for (int i = 0; i < n; i++) {
                int bit = (mask >> (n - 1 - i)) & 1;
                candidate[i] = bit ? '1' : '0';
            }
            if (seen.find(candidate) == seen.end()) {
                return candidate;
            }
        }
        return "";
    }
};

#endif //LEETCODE_FINDUNIQUEBINARYSTRING_HPP
