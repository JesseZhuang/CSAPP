#ifndef LEET_CODE_MINCOSTARRAYUNEQUAL_HPP
#define LEET_CODE_MINCOSTARRAYUNEQUAL_HPP

#include <vector>
#include <unordered_map>

using namespace std;

// lc 2499 pigeon hole
class MinCostArrayUnequal {
public:
    long long minimumTotalCost(vector<int> &nums1, vector<int> &nums2) {//216ms, 111Mb.
        int maxFreq = 0, maxFreqVal = 0, swaps = 0;
        long long int res = 0; // note return type is not int
        unordered_map<int, int> freq;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[i]) {
                freq[nums1[i]]++;
                swaps++;
                res += i;
                if (freq[nums1[i]] > maxFreq) {
                    maxFreqVal = nums1[i];
                    maxFreq = freq[nums1[i]];
                }
            }
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] != nums2[i] && nums1[i] != maxFreqVal && nums2[i] != maxFreqVal && swaps++ < 2 * maxFreq)
                res += i;
        }
        return swaps < 2 * maxFreq ? -1 : res;
    }

    long long minimumTotalCost2(vector<int> &nums1, vector<int> &nums2) {// 175ms, 107.1Mb.
        int maxFreqVal = 0, swaps = 0;
        long long int res = 0;
        int freq[nums1.size() + 1]; // use vector, default init to 0, 203ms, 109.3Mb.
        for (int i = 0; i < nums1.size() + 1; ++i) freq[i] = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[i]) {
                freq[nums1[i]]++;
                swaps++;
                res += i;
                if (freq[nums1[i]] > freq[maxFreqVal]) maxFreqVal = nums1[i];
            }
        }
        if (swaps >= 2 * freq[maxFreqVal]) return res;
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] != nums2[i] && nums1[i] != maxFreqVal && nums2[i] != maxFreqVal) {
                res += i;
                swaps++;
                if (swaps >= 2 * freq[maxFreqVal]) return res;
            }
        }
        return -1;
    }
};


#endif //LEET_CODE_MINCOSTARRAYUNEQUAL_HPP
