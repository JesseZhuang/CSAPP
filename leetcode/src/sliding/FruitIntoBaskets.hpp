#ifndef FRUIT_INTO_BASKETS_HPP
#define FRUIT_INTO_BASKETS_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// leet 904, medium, tags: array, hash table, sliding window.
class FruitIntoBaskets {
public:
    // solution 1: sliding window + unordered_map. O(n) time, O(1) space (at most 3 keys).
    static int totalFruit(const vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int res = 0, left = 0;
        for (int right = 0; right < (int)fruits.size(); ++right) {
            cnt[fruits[right]]++;
            while ((int)cnt.size() > 2) {
                if (--cnt[fruits[left]] == 0) cnt.erase(fruits[left]);
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }

    // solution 2: track last two types. O(n) time, O(1) space.
    // a,b are the two fruit types in the window, b is always the most recent.
    // cntB is the length of the latest consecutive run of b.
    static int totalFruit2(const vector<int>& fruits) {
        int a = -1, b = -1, cntB = 0, cur = 0, res = 0;
        for (int f : fruits) {
            if (f == a || f == b) {
                cur++;
            } else {
                cur = cntB + 1;
            }
            if (f == b) {
                cntB++;
            } else {
                cntB = 1;
                a = b;
                b = f;
            }
            res = max(res, cur);
        }
        return res;
    }
};

#endif
