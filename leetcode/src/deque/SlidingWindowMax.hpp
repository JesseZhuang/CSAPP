#ifndef SLIDINGWINDOWMAX_HPP
#define SLIDINGWINDOWMAX_HPP
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        size_t n = nums.size(), l = n - (k - 1);
        vector<int> res(l);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            // important i declared as int, size_t i-(k-1) cast to unsigned long underflow
            if (!dq.empty() && (dq.front() < i - (k - 1))) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res[i - (k - 1)] = nums[dq.front()];
        }
        return res;
    }
};


#endif //SLIDINGWINDOWMAX_HPP
