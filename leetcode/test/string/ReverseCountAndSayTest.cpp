#include "gtest/gtest.h"
#include "string/CountAndSay.hpp"
#include "string/ReverseCountAndSay.hpp"

#include <stdexcept>

using namespace std;

TEST(string, reverse_count_and_say_empty) {
    SolutionReverseCountAndSay sol;
    ASSERT_EQ("", sol.reverseCountSay(""));
}

TEST(string, reverse_count_and_say_example) {
    SolutionReverseCountAndSay sol;
    ASSERT_EQ("1211", sol.reverseCountSay("111221"));
}

TEST(string, reverse_count_and_say_single_pair) {
    SolutionReverseCountAndSay sol;
    ASSERT_EQ("3", sol.reverseCountSay("13"));
    ASSERT_EQ("11", sol.reverseCountSay("21"));
    ASSERT_EQ("222", sol.reverseCountSay("32"));
}

TEST(string, reverse_count_and_say_count_nine) {
    SolutionReverseCountAndSay sol;
    ASSERT_EQ("777777777", sol.reverseCountSay("97"));
}

TEST(string, reverse_count_and_say_zero_count) {
    SolutionReverseCountAndSay sol;
    ASSERT_EQ("5", sol.reverseCountSay("0415"));
}

TEST(string, reverse_count_and_say_multiple_pairs) {
    SolutionReverseCountAndSay sol;
    ASSERT_EQ("111111", sol.reverseCountSay("112131"));
}

TEST(string, reverse_count_and_say_round_trip) {
    SolutionCountAndSay cas;
    SolutionReverseCountAndSay rev;
    for (int n = 2; n <= 10; ++n) {
        ASSERT_EQ(cas.countAndSay(n - 1), rev.reverseCountSay(cas.countAndSay(n))) << "n=" << n;
    }
}

TEST(string, reverse_count_and_say_odd_length_throws) {
    SolutionReverseCountAndSay sol;
    ASSERT_THROW(sol.reverseCountSay("123"), invalid_argument);
}
