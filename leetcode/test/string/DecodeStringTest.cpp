#include "gtest/gtest.h"
#include "string/DecodeString.hpp"

TEST(string, decode_string_stack) {
    Solution394 tbt;
    ASSERT_EQ(tbt.decodeString("3[a]2[bc]"), "aaabcbc");
    ASSERT_EQ(tbt.decodeString("3[a2[c]]"), "accaccacc");
    ASSERT_EQ(tbt.decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef");
    ASSERT_EQ(tbt.decodeString("abc"), "abc");
    ASSERT_EQ(tbt.decodeString("1[a]"), "a");
    ASSERT_EQ(tbt.decodeString("10[a]"), "aaaaaaaaaa");
    ASSERT_EQ(tbt.decodeString("2[a2[b3[c]]]"), "abcccbcccabcccbccc");
    ASSERT_EQ(tbt.decodeString(""), "");
    ASSERT_EQ(tbt.decodeString("2[a]2[b]"), "aabb");
}

TEST(string, decode_string_recursive) {
    Solution394V2 tbt;
    ASSERT_EQ(tbt.decodeString("3[a]2[bc]"), "aaabcbc");
    ASSERT_EQ(tbt.decodeString("3[a2[c]]"), "accaccacc");
    ASSERT_EQ(tbt.decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef");
    ASSERT_EQ(tbt.decodeString("abc"), "abc");
    ASSERT_EQ(tbt.decodeString("1[a]"), "a");
    ASSERT_EQ(tbt.decodeString("10[a]"), "aaaaaaaaaa");
    ASSERT_EQ(tbt.decodeString("2[a2[b3[c]]]"), "abcccbcccabcccbccc");
    ASSERT_EQ(tbt.decodeString(""), "");
    ASSERT_EQ(tbt.decodeString("2[a]2[b]"), "aabb");
}
