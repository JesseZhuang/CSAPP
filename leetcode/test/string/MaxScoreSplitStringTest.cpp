#include "gtest/gtest.h"
#include "string/MaxScoreSplitString.hpp"

TEST(string, max_score_split_string) {
    MaxScoreSplitString sol;
    ASSERT_EQ(5, sol.maxScore("011101"));
    ASSERT_EQ(5, sol.maxScore("00111"));
    ASSERT_EQ(3, sol.maxScore("1111"));
}
