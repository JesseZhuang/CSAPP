#include "gtest/gtest.h"
#include "string/ReconstructDigits.hpp"

TEST(string, reconstruct_digits) {
    Solution423 sol;
    ASSERT_EQ(sol.originalDigits("owoztneoer"), "012");
    ASSERT_EQ(sol.originalDigits("fviefuro"), "45");
    ASSERT_EQ(sol.originalDigits("zeroonetwothreefourfivesixseveneightnine"), "0123456789");
}
