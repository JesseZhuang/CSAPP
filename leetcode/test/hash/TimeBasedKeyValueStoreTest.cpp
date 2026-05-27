#include "gtest/gtest.h"
#include "hash/TimeBasedKeyValueStore.hpp"

#include <string>

using namespace std;

TEST(hash, time_based_key_value_store) {
    TimeMap tm;
    tm.set("foo", "bar", 1);
    ASSERT_EQ("bar", tm.get("foo", 1));
    ASSERT_EQ("bar", tm.get("foo", 3));
    tm.set("foo", "bar2", 4);
    ASSERT_EQ("bar2", tm.get("foo", 4));
    ASSERT_EQ("bar2", tm.get("foo", 5));
    ASSERT_EQ("bar", tm.get("foo", 3));
    ASSERT_EQ("", tm.get("foo", 0));
    ASSERT_EQ("", tm.get("baz", 1));
}

TEST(hash, time_based_key_value_store_map) {
    TimeMap2 tm;
    tm.set("foo", "bar", 1);
    ASSERT_EQ("bar", tm.get("foo", 1));
    ASSERT_EQ("bar", tm.get("foo", 3));
    tm.set("foo", "bar2", 4);
    ASSERT_EQ("bar2", tm.get("foo", 4));
    ASSERT_EQ("bar2", tm.get("foo", 5));
    ASSERT_EQ("bar", tm.get("foo", 3));
    ASSERT_EQ("", tm.get("foo", 0));
    ASSERT_EQ("", tm.get("baz", 1));
}

TEST(hash, time_based_key_value_store_multiple_keys) {
    TimeMap tm;
    tm.set("a", "v1", 1);
    tm.set("b", "v2", 2);
    tm.set("a", "v3", 3);
    ASSERT_EQ("v1", tm.get("a", 2));
    ASSERT_EQ("v3", tm.get("a", 3));
    ASSERT_EQ("v2", tm.get("b", 5));
    ASSERT_EQ("", tm.get("b", 1));
}

TEST(hash, time_based_key_value_store_map_multiple_keys) {
    TimeMap2 tm;
    tm.set("a", "v1", 1);
    tm.set("b", "v2", 2);
    tm.set("a", "v3", 3);
    ASSERT_EQ("v1", tm.get("a", 2));
    ASSERT_EQ("v3", tm.get("a", 3));
    ASSERT_EQ("v2", tm.get("b", 5));
    ASSERT_EQ("", tm.get("b", 1));
}
