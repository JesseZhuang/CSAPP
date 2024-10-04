#include "gtest/gtest.h"
#include "hash/IsomorphicString.hpp"

TEST(hash, isomorphic_string) {
    IsomorphicString tbt;
    ASSERT_TRUE(tbt.isIsomorphicMap("paper", "title"));
    ASSERT_TRUE(tbt.isIsomorphicArray2("paper", "title"));
}
