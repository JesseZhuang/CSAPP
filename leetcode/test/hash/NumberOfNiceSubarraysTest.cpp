#include "gtest/gtest.h"
#include "hash/NumberOfNiceSubarrays.hpp"
#include <vector>
using namespace std;

TEST(hash, number_of_nice_subarrays) {
    SolutionNumberOfNiceSubarrays sol;

    vector<int> v1{1, 1, 2, 1, 1};
    ASSERT_EQ(2, sol.numberOfSubarrays(v1, 3));
    ASSERT_EQ(2, sol.numberOfSubarraysSliding(v1, 3));

    vector<int> v2{2, 4, 6};
    ASSERT_EQ(0, sol.numberOfSubarrays(v2, 1));
    ASSERT_EQ(0, sol.numberOfSubarraysSliding(v2, 1));

    vector<int> v3{2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    ASSERT_EQ(16, sol.numberOfSubarrays(v3, 2));
    ASSERT_EQ(16, sol.numberOfSubarraysSliding(v3, 2));

    vector<int> v4{1, 3, 5, 7};
    ASSERT_EQ(3, sol.numberOfSubarrays(v4, 2));
    ASSERT_EQ(3, sol.numberOfSubarraysSliding(v4, 2));

    vector<int> v5{2, 4, 1, 6, 8};
    ASSERT_EQ(9, sol.numberOfSubarrays(v5, 1));
    ASSERT_EQ(9, sol.numberOfSubarraysSliding(v5, 1));

    vector<int> v6{2, 1, 2, 3, 2, 2};
    ASSERT_EQ(6, sol.numberOfSubarrays(v6, 2));
    ASSERT_EQ(6, sol.numberOfSubarraysSliding(v6, 2));
    ASSERT_EQ(0, sol.numberOfSubarrays(v6, 3));
    ASSERT_EQ(0, sol.numberOfSubarraysSliding(v6, 3));

    vector<int> v7{1};
    ASSERT_EQ(1, sol.numberOfSubarrays(v7, 1));
    ASSERT_EQ(1, sol.numberOfSubarraysSliding(v7, 1));

    vector<int> large(49999, 100000);
    large[24999] = 99999;
    ASSERT_EQ(625000000, sol.numberOfSubarrays(large, 1));
    ASSERT_EQ(625000000, sol.numberOfSubarraysSliding(large, 1));
}
