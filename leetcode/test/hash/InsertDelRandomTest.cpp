#include "gtest/gtest.h"
#include "hash/InsertDelRandom.hpp"

#include <unordered_set>

using namespace std;

TEST(hash, insert_del_random) {
    Solution380::RandomizedSet rs;

    // Example from problem
    ASSERT_TRUE(rs.insert(1));
    ASSERT_FALSE(rs.remove(2));  // not present
    ASSERT_TRUE(rs.insert(2));
    // getRandom should return 1 or 2
    unordered_set<int> possible{1, 2};
    for (int i = 0; i < 20; i++) {
        int r = rs.getRandom();
        ASSERT_TRUE(possible.count(r)) << "unexpected value: " << r;
    }
    ASSERT_TRUE(rs.remove(1));
    ASSERT_FALSE(rs.insert(2));  // duplicate
    ASSERT_EQ(2, rs.getRandom());  // only element

    // Duplicates: insert same value twice
    Solution380::RandomizedSet rs2;
    ASSERT_TRUE(rs2.insert(5));
    ASSERT_FALSE(rs2.insert(5));

    // Remove nonexistent
    ASSERT_FALSE(rs2.remove(99));

    // Reinsert after removal
    ASSERT_TRUE(rs2.remove(5));
    ASSERT_TRUE(rs2.insert(5));
    ASSERT_EQ(5, rs2.getRandom());

    // Single element
    Solution380::RandomizedSet rs3;
    ASSERT_TRUE(rs3.insert(42));
    ASSERT_EQ(42, rs3.getRandom());
    ASSERT_TRUE(rs3.remove(42));
    ASSERT_TRUE(rs3.insert(7));
    ASSERT_EQ(7, rs3.getRandom());
}
