#include "stack/SimplifyPath.hpp"
#include <gtest/gtest.h>

TEST(stack, simplify_path_basic) { EXPECT_EQ("/home", SimplifyPath::simplifyPath("/home/")); }
TEST(stack, simplify_path_double_dot) { EXPECT_EQ("/", SimplifyPath::simplifyPath("/../")); }
TEST(stack, simplify_path_multiple_slashes) { EXPECT_EQ("/home/foo", SimplifyPath::simplifyPath("/home//foo/")); }
TEST(stack, simplify_path_complex) { EXPECT_EQ("/c", SimplifyPath::simplifyPath("/a/./b/../../c/")); }
TEST(stack, simplify_path_root) { EXPECT_EQ("/", SimplifyPath::simplifyPath("/")); }
TEST(stack, simplify_path_deep) { EXPECT_EQ("/a/b/c/d", SimplifyPath::simplifyPath("/a/b/c/d")); }
TEST(stack, simplify_path_triple_dots) { EXPECT_EQ("/...", SimplifyPath::simplifyPath("/...")); }
TEST(stack, simplify_path_middle) { EXPECT_EQ("/a/c/e", SimplifyPath::simplifyPath("/a/b/../c/d/../e")); }
TEST(stack, simplify_path_pop_beyond) { EXPECT_EQ("/b", SimplifyPath::simplifyPath("/a/../../b")); }
