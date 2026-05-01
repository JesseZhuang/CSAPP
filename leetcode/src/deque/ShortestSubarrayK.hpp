#ifndef LEETCODE_SHORTESTSUBARRAYK_HPP
#define LEETCODE_SHORTESTSUBARRAYK_HPP

#include <vector>
#include <deque>

using namespace std;

class ShortestSubarrayK {
public:
    // O(n) time, O(n) space.
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size(), res = n + 1;
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        deque<int> dq;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return res <= n ? res : -1;
    }
};

#endif //LEETCODE_SHORTESTSUBARRAYK_HPP
