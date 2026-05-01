#include "gtest/gtest.h"
#include "list/LRUCache.hpp"

using namespace std;

TEST(list, lru_cache_example1) {
    LRUCacheCpp c(2);
    c.put(1, 1);
    c.put(2, 2);
    ASSERT_EQ(1, c.get(1));
    c.put(3, 3);            // evict key 2
    ASSERT_EQ(-1, c.get(2));
    c.put(4, 4);            // evict key 1
    ASSERT_EQ(-1, c.get(1));
    ASSERT_EQ(3, c.get(3));
    ASSERT_EQ(4, c.get(4));
}

TEST(list, lru_cache_miss_returns_minus_one) {
    LRUCacheCpp c(1);
    ASSERT_EQ(-1, c.get(0));
}

TEST(list, lru_cache_put_updates_and_marks_recent) {
    LRUCacheCpp c(2);
    c.put(1, 10);
    c.put(2, 20);
    c.put(1, 100); // update + mark 1 as MRU
    c.put(3, 30);  // evict 2
    ASSERT_EQ(100, c.get(1));
    ASSERT_EQ(-1, c.get(2));
    ASSERT_EQ(30, c.get(3));
}

TEST(list, lru_cache_capacity_one) {
    LRUCacheCpp c(1);
    c.put(1, 1);
    ASSERT_EQ(1, c.get(1));
    c.put(2, 2);
    ASSERT_EQ(-1, c.get(1));
    ASSERT_EQ(2, c.get(2));
}

TEST(list, lru_cache_get_promotes_lru) {
    LRUCacheCpp c(3);
    c.put(1, 1);
    c.put(2, 2);
    c.put(3, 3);
    ASSERT_EQ(1, c.get(1));  // promote 1, LRU is now 2
    c.put(4, 4);             // evict 2
    ASSERT_EQ(-1, c.get(2));
    ASSERT_EQ(1, c.get(1));
    ASSERT_EQ(3, c.get(3));
    ASSERT_EQ(4, c.get(4));
}

TEST(list, lru_cache_many_inserts_within_capacity) {
    LRUCacheCpp c(5);
    for (int i = 0; i < 5; ++i) c.put(i, i * 10);
    for (int i = 0; i < 5; ++i) ASSERT_EQ(i * 10, c.get(i));
}

TEST(list, lru_cache_overwrites_dont_change_size) {
    LRUCacheCpp c(2);
    c.put(1, 1);
    c.put(1, 2);
    c.put(1, 3);
    c.put(2, 2);
    ASSERT_EQ(3, c.get(1));
    ASSERT_EQ(2, c.get(2));
}

TEST(list, lru_cache_eviction_order_after_mixed_ops) {
    LRUCacheCpp c(3);
    c.put(1, 1);
    c.put(2, 2);
    c.put(3, 3);
    c.put(4, 4); // evict 1 (LRU). order: 4,3,2
    ASSERT_EQ(-1, c.get(1));
    ASSERT_EQ(2, c.get(2)); // promote 2. order: 2,4,3
    c.put(5, 5);            // evict 3 (LRU). order: 5,2,4
    ASSERT_EQ(-1, c.get(3));
    ASSERT_EQ(4, c.get(4));
    ASSERT_EQ(2, c.get(2));
    ASSERT_EQ(5, c.get(5));
}
