#include "gtest/gtest.h"
#include "tree/DesignFileSystem.hpp"

TEST(tree, design_file_system_example1) {
    FileSystem fs;
    ASSERT_TRUE(fs.createPath("/a", 1));
    ASSERT_EQ(1, fs.get("/a"));
}

TEST(tree, design_file_system_example2) {
    FileSystem fs;
    ASSERT_TRUE(fs.createPath("/leet", 1));
    ASSERT_TRUE(fs.createPath("/leet/code", 2));
    ASSERT_EQ(2, fs.get("/leet/code"));
    ASSERT_FALSE(fs.createPath("/c/d", 1));
    ASSERT_EQ(-1, fs.get("/c"));
}
