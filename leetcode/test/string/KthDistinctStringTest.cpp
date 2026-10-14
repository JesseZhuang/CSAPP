#include "gtest/gtest.h"
#include "string/KthDistinctString.hpp"

TEST(string, kth_distinct_string_official_example) {
    Solution sol;
    std::vector<std::string> arr{"d", "b", "c", "b", "c", "a"};
    ASSERT_EQ("a", sol.kthDistinct(arr, 2));
}

TEST(string, kth_distinct_string_first_and_last_distinct) {
    Solution sol;
    std::vector<std::string> arr{"a", "b", "a", "c", "d", "d"};
    ASSERT_EQ("b", sol.kthDistinct(arr, 1));
    ASSERT_EQ("c", sol.kthDistinct(arr, 2));
}

TEST(string, kth_distinct_string_duplicates) {
    Solution sol;
    std::vector<std::string> arr{"a", "a", "b", "b"};
    ASSERT_EQ("", sol.kthDistinct(arr, 1));
}

TEST(string, kth_distinct_string_fewer_than_k) {
    Solution sol;
    std::vector<std::string> arr{"a", "b", "a", "c"};
    ASSERT_EQ("", sol.kthDistinct(arr, 3));
}

TEST(string, kth_distinct_string_single_element) {
    Solution sol;
    std::vector<std::string> arr{"only"};
    ASSERT_EQ("only", sol.kthDistinct(arr, 1));
}
