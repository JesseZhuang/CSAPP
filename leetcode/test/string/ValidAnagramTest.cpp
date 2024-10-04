#include "gtest/gtest.h"
#include "string/ValidAnagram.hpp"

TEST(string, valid_anagram) {
    ValidAnagram va;
    ASSERT_TRUE(va.isAnagram("anagram", "nagaram"));
    ASSERT_FALSE(va.isAnagram("rat", "car"));
    ASSERT_FALSE(va.isAnagramArray("rat", "car"));
}
