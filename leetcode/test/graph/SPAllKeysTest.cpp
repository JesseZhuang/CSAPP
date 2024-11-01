#include "gtest/gtest.h"
#include "graph/SPAllKeys.hpp"

using namespace std;

TEST(graph, sp_all_keys) {
    Solution tbt;
    vector<string> input{"@.a..", "###.#", "b.A.B"};
    ASSERT_EQ(8, tbt.shortestPathAllKeys(input));
    ASSERT_EQ(1 + SIZE_MAX, 0); // overflow, +max same to -1
}
