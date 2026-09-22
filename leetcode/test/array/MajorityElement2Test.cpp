#include "gtest/gtest.h"
#include "array/MajorityElement2.hpp"
#include <vector>

using namespace std;

TEST(array, majority_element_2_voting) {
    Solution2 sol;

    // Example 1: [3,2,3]
    {
        vector<int> nums = {3, 2, 3};
        vector<int> expected = {3};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // Example 2: [1]
    {
        vector<int> nums = {1};
        vector<int> expected = {1};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // Example 3: [1,2]
    {
        vector<int> nums = {1, 2};
        vector<int> expected = {1, 2};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // No majority element
    {
        vector<int> nums = {1, 2, 3};
        vector<int> expected = {};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // Two majority elements
    {
        vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
        vector<int> expected = {1, 2};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // All same
    {
        vector<int> nums = {5, 5, 5, 5};
        vector<int> expected = {5};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // Negative numbers
    {
        vector<int> nums = {-1, -1, -1, 2, 3};
        vector<int> expected = {-1};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // Large values at boundary
    {
        vector<int> nums = {1000000000, 1000000000, -1000000000, -1000000000, 0};
        vector<int> expected = {-1000000000, 1000000000};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // Single repeated element with others
    {
        vector<int> nums = {1, 2, 1, 1, 3, 1};
        vector<int> expected = {1};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }

    // Two elements only
    {
        vector<int> nums = {0, 0, 0};
        vector<int> expected = {0};
        EXPECT_EQ(sol.majorityElementVoting(nums), expected);
    }
}

TEST(array, majority_element_2_map) {
    Solution2 sol;

    // Example 1: [3,2,3]
    {
        vector<int> nums = {3, 2, 3};
        vector<int> expected = {3};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // Example 2: [1]
    {
        vector<int> nums = {1};
        vector<int> expected = {1};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // Example 3: [1,2]
    {
        vector<int> nums = {1, 2};
        vector<int> expected = {1, 2};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // No majority element
    {
        vector<int> nums = {1, 2, 3};
        vector<int> expected = {};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // Two majority elements
    {
        vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
        vector<int> expected = {1, 2};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // All same
    {
        vector<int> nums = {5, 5, 5, 5};
        vector<int> expected = {5};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // Negative numbers
    {
        vector<int> nums = {-1, -1, -1, 2, 3};
        vector<int> expected = {-1};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // Large values at boundary
    {
        vector<int> nums = {1000000000, 1000000000, -1000000000, -1000000000, 0};
        vector<int> expected = {-1000000000, 1000000000};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // Single repeated element with others
    {
        vector<int> nums = {1, 2, 1, 1, 3, 1};
        vector<int> expected = {1};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }

    // Two elements only
    {
        vector<int> nums = {0, 0, 0};
        vector<int> expected = {0};
        EXPECT_EQ(sol.majorityElementMap(nums), expected);
    }
}
