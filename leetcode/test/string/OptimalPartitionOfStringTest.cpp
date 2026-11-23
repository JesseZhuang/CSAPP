#include "string/OptimalPartitionOfString.hpp"

#include <gtest/gtest.h>
#include <string>

namespace {
void expectPartitions(const std::string& input, int expected) {
    optimal_partition_of_string::Solution solution;
    EXPECT_EQ(solution.partitionString(input), expected);
    EXPECT_EQ(solution.partitionStringBitmask(input), expected);
}
} // namespace

TEST(string, optimal_partition_of_string_repeated_letters) {
    expectPartitions("abacaba", 4);
}

TEST(string, optimal_partition_of_string_all_same) {
    expectPartitions("ssssss", 6);
}

TEST(string, optimal_partition_of_string_single_letter) {
    expectPartitions("s", 1);
}

TEST(string, optimal_partition_of_string_all_distinct) {
    expectPartitions("abcdefghijklmnopqrstuvwxyz", 1);
}

TEST(string, optimal_partition_of_string_repeat_after_full_alphabet) {
    expectPartitions("abcdefghijklmnopqrstuvwxyzabc", 2);
}

TEST(string, optimal_partition_of_string_max_length) {
    expectPartitions(std::string(100000, 'a'), 100000);
}
