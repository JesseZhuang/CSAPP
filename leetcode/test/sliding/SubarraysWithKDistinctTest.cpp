#include "gtest/gtest.h"
#include "sliding/SubarraysWithKDistinct.hpp"

TEST(sliding, subarrays_with_k_distinct) {
    EXPECT_EQ(7, SubarraysWithKDistinct::subarraysWithKDistinct({1, 2, 1, 2, 3}, 2));
    EXPECT_EQ(3, SubarraysWithKDistinct::subarraysWithKDistinct({1, 2, 1, 3, 4}, 3));
    EXPECT_EQ(3, SubarraysWithKDistinct::subarraysWithKDistinct({1, 2, 1}, 1));
    EXPECT_EQ(2, SubarraysWithKDistinct::subarraysWithKDistinct({1, 2, 1, 3}, 3));
    EXPECT_EQ(0, SubarraysWithKDistinct::subarraysWithKDistinct({1, 2, 1, 3}, 4));

    vector<int> nums(20000, 1);
    EXPECT_EQ(200010000, SubarraysWithKDistinct::subarraysWithKDistinct(nums, 1));
}
