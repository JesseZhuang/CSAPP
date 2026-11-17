#include "gtest/gtest.h"
#include "array/MaximizeGreatness.hpp"

#include <vector>

using namespace std;

TEST(array, maximize_greatness) {
    Solution sol;

    vector<int> example1{1, 3, 5, 2, 1, 3, 1};
    EXPECT_EQ(4, sol.maximizeGreatness(example1));

    vector<int> example2{1, 2, 3, 4};
    EXPECT_EQ(3, sol.maximizeGreatness(example2));

    vector<int> duplicate_values{1, 3, 5, 2, 1};
    EXPECT_EQ(3, sol.maximizeGreatness(duplicate_values));

    vector<int> all_equal{7, 7, 7, 7};
    EXPECT_EQ(0, sol.maximizeGreatness(all_equal));

    vector<int> singleton{42};
    EXPECT_EQ(0, sol.maximizeGreatness(singleton));

    vector<int> duplicates{1, 1, 1, 2, 2, 3};
    EXPECT_EQ(3, sol.maximizeGreatness(duplicates));

    vector<int> high_values{1000000000, 999999999, 1000000000, 999999998};
    EXPECT_EQ(2, sol.maximizeGreatness(high_values));
}
