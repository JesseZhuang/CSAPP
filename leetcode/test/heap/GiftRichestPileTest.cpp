#include "gtest/gtest.h"
#include "heap/GiftRichestPile.hpp"

using namespace std;

TEST(heap, gift_richest_pile) {
    ASSERT_EQ(sqrt(100), 10);
    ASSERT_EQ(sqrt(2), 1.4142135623730951);
    priority_queue<int> pq;
    pq.emplace(3.3); // auto cast to int
    pq.emplace(sqrt(2));
    ASSERT_EQ(3, pq.top());
    pq.pop();
    ASSERT_EQ(1, pq.top());
    pq.pop();
}
