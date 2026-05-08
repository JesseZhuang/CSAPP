#ifndef LEETCODE_MEDIANFINDER_HPP
#define LEETCODE_MEDIANFINDER_HPP

#include <queue>
#include <set>

using namespace std;

// leet 295 — Find Median from Data Stream

// Approach 1: Two Heaps
// max-heap for lower half, min-heap for upper half
// Invariant: maxHeap.size() == minHeap.size() or maxHeap.size() == minHeap.size() + 1
// addNum: O(log n), findMedian: O(1)
class MedianFinderHeap {
    priority_queue<int> lo;                            // max-heap (lower half)
    priority_queue<int, vector<int>, greater<>> hi;    // min-heap (upper half)
public:
    MedianFinderHeap() {}

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        // keep lo.size() >= hi.size()
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() > hi.size())
            return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};

// Approach 2: Multiset with two iterators (lo, hi)
// lo points to left-median, hi points to right-median.
// When size is odd, lo == hi. When even, hi = next(lo).
// addNum: O(log n), findMedian: O(1)
class MedianFinderMultiset {
    multiset<int> data;
    multiset<int>::iterator lo, hi;
public:
    MedianFinderMultiset() : lo(data.end()), hi(data.end()) {}

    void addNum(int num) {
        int n = data.size();
        data.insert(num);
        if (n == 0) {
            lo = hi = data.begin();
            return;
        }
        if (n % 2 == 1) {
            // was odd (lo == hi), becomes even => need lo and hi to split
            if (num < *lo) {
                --lo;       // new element went left of mid, lo shifts left
            } else {
                ++hi;       // new element went right of (or at) mid, hi shifts right
            }
        } else {
            // was even (hi = next(lo)), becomes odd => lo == hi
            if (num < *lo) {
                // inserted left of lo: new median is at lo (old lo)
                hi = lo;
            } else if (num >= *hi) {
                // inserted at or right of hi: new median is at hi (old hi)
                lo = hi;
            } else {
                // inserted between lo and hi: new median is the inserted element
                // find it — it's at next(lo) since it's between lo and hi
                lo = hi = next(lo);
            }
        }
    }

    double findMedian() {
        return (*lo + *hi) / 2.0;
    }
};

#endif //LEETCODE_MEDIANFINDER_HPP
