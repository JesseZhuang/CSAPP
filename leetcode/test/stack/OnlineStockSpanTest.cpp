#include "gtest/gtest.h"
#include "stack/OnlineStockSpan.hpp"

// Helper: run a sequence of prices through a spanner and return all spans
template <typename T>
vector<int> runSpanner(const vector<int> &prices) {
    T spanner;
    vector<int> result;
    for (int p : prices) {
        result.push_back(spanner.next(p));
    }
    return result;
}

// LeetCode example: [100, 80, 60, 70, 60, 75, 85] -> [1, 1, 1, 2, 1, 4, 6]
TEST(stack, online_stock_span_example1) {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> expected = {1, 1, 1, 2, 1, 4, 6};
    ASSERT_EQ(runSpanner<StockSpanner>(prices), expected);
    ASSERT_EQ(runSpanner<StockSpannerDP>(prices), expected);
}

TEST(stack, online_stock_span_all_increasing) {
    vector<int> prices = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};
    ASSERT_EQ(runSpanner<StockSpanner>(prices), expected);
    ASSERT_EQ(runSpanner<StockSpannerDP>(prices), expected);
}

TEST(stack, online_stock_span_all_decreasing) {
    vector<int> prices = {5, 4, 3, 2, 1};
    vector<int> expected = {1, 1, 1, 1, 1};
    ASSERT_EQ(runSpanner<StockSpanner>(prices), expected);
    ASSERT_EQ(runSpanner<StockSpannerDP>(prices), expected);
}

TEST(stack, online_stock_span_all_same) {
    vector<int> prices = {7, 7, 7, 7, 7};
    vector<int> expected = {1, 2, 3, 4, 5};
    ASSERT_EQ(runSpanner<StockSpanner>(prices), expected);
    ASSERT_EQ(runSpanner<StockSpannerDP>(prices), expected);
}

TEST(stack, online_stock_span_valley_and_peak) {
    vector<int> prices = {10, 5, 3, 5, 10};
    vector<int> expected = {1, 1, 1, 3, 5};
    ASSERT_EQ(runSpanner<StockSpanner>(prices), expected);
    ASSERT_EQ(runSpanner<StockSpannerDP>(prices), expected);
}

TEST(stack, online_stock_span_alternating) {
    vector<int> prices = {1, 3, 1, 3, 1, 3};
    vector<int> expected = {1, 2, 1, 4, 1, 6};
    ASSERT_EQ(runSpanner<StockSpanner>(prices), expected);
    ASSERT_EQ(runSpanner<StockSpannerDP>(prices), expected);
}

TEST(stack, online_stock_span_boundary_values) {
    // Single element
    {
        StockSpanner s;
        ASSERT_EQ(s.next(1), 1);
    }
    // Large price value
    {
        StockSpanner s;
        ASSERT_EQ(s.next(100000), 1);
        ASSERT_EQ(s.next(100000), 2);
    }
    // Min price value
    {
        StockSpannerDP s;
        ASSERT_EQ(s.next(1), 1);
        ASSERT_EQ(s.next(1), 2);
    }
}
