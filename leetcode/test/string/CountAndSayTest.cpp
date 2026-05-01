#include "gtest/gtest.h"
#include "string/CountAndSay.hpp"

using namespace std;

TEST(string, count_and_say_base) {
    SolutionCountAndSay sol;
    ASSERT_EQ("1", sol.countAndSay(1));
}

TEST(string, count_and_say_term2) {
    SolutionCountAndSay sol;
    ASSERT_EQ("11", sol.countAndSay(2));
}

TEST(string, count_and_say_term3) {
    SolutionCountAndSay sol;
    ASSERT_EQ("21", sol.countAndSay(3));
}

TEST(string, count_and_say_term4) {
    SolutionCountAndSay sol;
    ASSERT_EQ("1211", sol.countAndSay(4));
}

TEST(string, count_and_say_term5) {
    SolutionCountAndSay sol;
    ASSERT_EQ("111221", sol.countAndSay(5));
}

TEST(string, count_and_say_term6) {
    SolutionCountAndSay sol;
    ASSERT_EQ("312211", sol.countAndSay(6));
}

TEST(string, count_and_say_term7) {
    SolutionCountAndSay sol;
    ASSERT_EQ("13112221", sol.countAndSay(7));
}

TEST(string, count_and_say_term8) {
    SolutionCountAndSay sol;
    ASSERT_EQ("1113213211", sol.countAndSay(8));
}

TEST(string, count_and_say_term9) {
    SolutionCountAndSay sol;
    ASSERT_EQ("31131211131221", sol.countAndSay(9));
}

TEST(string, count_and_say_term10) {
    SolutionCountAndSay sol;
    ASSERT_EQ("13211311123113112211", sol.countAndSay(10));
}

TEST(string, count_and_say_only_digits_1_to_3) {
    SolutionCountAndSay sol;
    for (int i = 1; i <= 15; ++i) {
        for (char c : sol.countAndSay(i)) {
            ASSERT_TRUE(c == '1' || c == '2' || c == '3');
        }
    }
}

TEST(string, count_and_say_monotonic_length) {
    SolutionCountAndSay sol;
    int prev = 0;
    for (int i = 1; i <= 12; ++i) {
        int len = (int)sol.countAndSay(i).size();
        ASSERT_GE(len, prev);
        prev = len;
    }
}
