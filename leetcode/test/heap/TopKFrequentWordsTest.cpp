#include "gtest/gtest.h"
#include "heap/TopKFrequentWords.hpp"

using namespace std;

TEST(heap, top_k_frequent_words) {
    Solution692Heap sol;

    // basic example
    vector<string> w1 = {"i","love","leetcode","i","love","coding"};
    ASSERT_EQ(sol.topKFrequent(w1, 2), (vector<string>{"i","love"}));

    // tie-breaking by lex order
    vector<string> w2 = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    ASSERT_EQ(sol.topKFrequent(w2, 4), (vector<string>{"the","is","sunny","day"}));

    // single word
    vector<string> w3 = {"hello"};
    ASSERT_EQ(sol.topKFrequent(w3, 1), (vector<string>{"hello"}));

    // all same frequency, k = unique count -> lex order
    vector<string> w4 = {"c","a","b"};
    ASSERT_EQ(sol.topKFrequent(w4, 3), (vector<string>{"a","b","c"}));

    // all same frequency, k < unique count
    vector<string> w5 = {"c","a","b"};
    ASSERT_EQ(sol.topKFrequent(w5, 2), (vector<string>{"a","b"}));
}

TEST(heap, top_k_frequent_words_bucket) {
    Solution692Bucket sol;

    // basic example
    vector<string> w1 = {"i","love","leetcode","i","love","coding"};
    ASSERT_EQ(sol.topKFrequent(w1, 2), (vector<string>{"i","love"}));

    // tie-breaking by lex order
    vector<string> w2 = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    ASSERT_EQ(sol.topKFrequent(w2, 4), (vector<string>{"the","is","sunny","day"}));

    // single word
    vector<string> w3 = {"hello"};
    ASSERT_EQ(sol.topKFrequent(w3, 1), (vector<string>{"hello"}));

    // all same frequency, k = unique count -> lex order
    vector<string> w4 = {"c","a","b"};
    ASSERT_EQ(sol.topKFrequent(w4, 3), (vector<string>{"a","b","c"}));

    // all same frequency, k < unique count
    vector<string> w5 = {"c","a","b"};
    ASSERT_EQ(sol.topKFrequent(w5, 2), (vector<string>{"a","b"}));
}
