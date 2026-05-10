#include "gtest/gtest.h"
#include "array/PartitionLabels.hpp"

// Solution 1: Greedy
TEST(array, partition_labels_greedy_example1) {
    SolutionPartitionLabels sol;
    EXPECT_EQ(sol.partitionLabels("ababcbacadefegdehijhklij"), (vector<int>{9, 7, 8}));
}

TEST(array, partition_labels_greedy_example2) {
    SolutionPartitionLabels sol;
    EXPECT_EQ(sol.partitionLabels("eccbbbbdec"), (vector<int>{10}));
}

TEST(array, partition_labels_greedy_single) {
    SolutionPartitionLabels sol;
    EXPECT_EQ(sol.partitionLabels("a"), (vector<int>{1}));
}

TEST(array, partition_labels_greedy_all_same) {
    SolutionPartitionLabels sol;
    EXPECT_EQ(sol.partitionLabels("aaaaa"), (vector<int>{5}));
}

TEST(array, partition_labels_greedy_all_unique) {
    SolutionPartitionLabels sol;
    EXPECT_EQ(sol.partitionLabels("abcd"), (vector<int>{1, 1, 1, 1}));
}

TEST(array, partition_labels_greedy_two_groups) {
    SolutionPartitionLabels sol;
    EXPECT_EQ(sol.partitionLabels("aabb"), (vector<int>{2, 2}));
}

TEST(array, partition_labels_greedy_overlap) {
    SolutionPartitionLabels sol;
    EXPECT_EQ(sol.partitionLabels("abcbad"), (vector<int>{5, 1}));
}

TEST(array, partition_labels_greedy_wrap) {
    SolutionPartitionLabels sol;
    EXPECT_EQ(sol.partitionLabels("abcdefghijklmnopqrstuvwxyza"), (vector<int>{27}));
}

// Solution 2: Merge Intervals
TEST(array, partition_labels_merge_example1) {
    SolutionPartitionLabels2 sol;
    EXPECT_EQ(sol.partitionLabels("ababcbacadefegdehijhklij"), (vector<int>{9, 7, 8}));
}

TEST(array, partition_labels_merge_example2) {
    SolutionPartitionLabels2 sol;
    EXPECT_EQ(sol.partitionLabels("eccbbbbdec"), (vector<int>{10}));
}

TEST(array, partition_labels_merge_single) {
    SolutionPartitionLabels2 sol;
    EXPECT_EQ(sol.partitionLabels("a"), (vector<int>{1}));
}

TEST(array, partition_labels_merge_all_same) {
    SolutionPartitionLabels2 sol;
    EXPECT_EQ(sol.partitionLabels("aaaaa"), (vector<int>{5}));
}

TEST(array, partition_labels_merge_all_unique) {
    SolutionPartitionLabels2 sol;
    EXPECT_EQ(sol.partitionLabels("abcd"), (vector<int>{1, 1, 1, 1}));
}

TEST(array, partition_labels_merge_two_groups) {
    SolutionPartitionLabels2 sol;
    EXPECT_EQ(sol.partitionLabels("aabb"), (vector<int>{2, 2}));
}

TEST(array, partition_labels_merge_overlap) {
    SolutionPartitionLabels2 sol;
    EXPECT_EQ(sol.partitionLabels("abcbad"), (vector<int>{5, 1}));
}

TEST(array, partition_labels_merge_wrap) {
    SolutionPartitionLabels2 sol;
    EXPECT_EQ(sol.partitionLabels("abcdefghijklmnopqrstuvwxyza"), (vector<int>{27}));
}
