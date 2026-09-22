#ifndef LEETCODE_MAJORITYELEMENT2_HPP
#define LEETCODE_MAJORITYELEMENT2_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    // Boyer-Moore Voting extended to n/3: O(n) time, O(1) space
    vector<int> majorityElementVoting(vector<int>& nums) {
        int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == cand1) {
                cnt1++;
            } else if (num == cand2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cand1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                cand2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        // Verify candidates
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == cand1) cnt1++;
            else if (num == cand2) cnt2++;
        }
        vector<int> result;
        int n = nums.size();
        if (cnt1 > n / 3) result.push_back(cand1);
        if (cnt2 > n / 3) result.push_back(cand2);
        sort(result.begin(), result.end());
        return result;
    }

    // HashMap counting: O(n) time, O(n) space
    vector<int> majorityElementMap(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        vector<int> result;
        for (int num : nums) {
            counts[num]++;
        }
        for (auto& [val, cnt] : counts) {
            if (cnt > n / 3) {
                result.push_back(val);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

#endif //LEETCODE_MAJORITYELEMENT2_HPP
