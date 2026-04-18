#include "gtest/gtest.h"
#include "heap/TopKFrequentElements.hpp"

#include <algorithm>

using namespace std;

TEST(heap, top_k_frequent_elements_bucket) {
    Solution347Bucket sol;
    vector<int> v1 = {1,1,1,2,2,3};
    auto r1 = sol.topKFrequent(v1, 2);
    sort(r1.begin(), r1.end());
    ASSERT_EQ(r1, (vector<int>{1, 2}));

    vector<int> v2 = {1};
    ASSERT_EQ(sol.topKFrequent(v2, 1), (vector<int>{1}));

    vector<int> v3 = {-1,-1,-2,-2,-2,-3};
    auto r3 = sol.topKFrequent(v3, 2);
    sort(r3.begin(), r3.end());
    ASSERT_EQ(r3, (vector<int>{-2, -1}));

    vector<int> v4 = {5,5,5,5};
    ASSERT_EQ(sol.topKFrequent(v4, 1), (vector<int>{5}));

    vector<int> v5 = {4,4,4,1,1,2,2,2,3};
    auto r5 = sol.topKFrequent(v5, 3);
    sort(r5.begin(), r5.end());
    ASSERT_EQ(r5, (vector<int>{1, 2, 4}));
}

TEST(heap, top_k_frequent_elements_heap) {
    Solution347Heap sol;
    vector<int> v1 = {1,1,1,2,2,3};
    auto r1 = sol.topKFrequent(v1, 2);
    sort(r1.begin(), r1.end());
    ASSERT_EQ(r1, (vector<int>{1, 2}));

    vector<int> v2 = {1};
    ASSERT_EQ(sol.topKFrequent(v2, 1), (vector<int>{1}));

    vector<int> v3 = {-1,-1,-2,-2,-2,-3};
    auto r3 = sol.topKFrequent(v3, 2);
    sort(r3.begin(), r3.end());
    ASSERT_EQ(r3, (vector<int>{-2, -1}));

    vector<int> v4 = {5,5,5,5};
    ASSERT_EQ(sol.topKFrequent(v4, 1), (vector<int>{5}));

    vector<int> v5 = {4,4,4,1,1,2,2,2,3};
    auto r5 = sol.topKFrequent(v5, 3);
    sort(r5.begin(), r5.end());
    ASSERT_EQ(r5, (vector<int>{1, 2, 4}));
}
