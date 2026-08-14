#include <gtest/gtest.h>
#include "binary_search/SuccessfulPairs.hpp"

TEST(binary_search, successful_pairs) {
    Solution s;

    // Example 1
    vector<int> spells1 = {5, 1, 3};
    vector<int> potions1 = {1, 2, 3, 4, 5};
    vector<int> expected1 = {4, 0, 3};
    EXPECT_EQ(expected1, s.successfulPairs(spells1, potions1, 7));

    // Example 2
    vector<int> spells2 = {3, 1, 2};
    vector<int> potions2 = {8, 5, 8};
    vector<int> expected2 = {2, 0, 2};
    EXPECT_EQ(expected2, s.successfulPairs(spells2, potions2, 16));

    // Single spell, all succeed
    vector<int> spells3 = {10};
    vector<int> potions3 = {1, 2, 3};
    vector<int> expected3 = {3};
    EXPECT_EQ(expected3, s.successfulPairs(spells3, potions3, 5));

    // Single spell, none succeed
    vector<int> spells4 = {1};
    vector<int> potions4 = {1, 2, 3};
    vector<int> expected4 = {0};
    EXPECT_EQ(expected4, s.successfulPairs(spells4, potions4, 100));

    // Large values requiring long long
    vector<int> spells5 = {100000};
    vector<int> potions5 = {100000};
    vector<int> expected5 = {1};
    EXPECT_EQ(expected5, s.successfulPairs(spells5, potions5, (long long)100000 * 100000));

    // spell = 1, boundary
    vector<int> spells6 = {1};
    vector<int> potions6 = {3, 5, 7, 9};
    vector<int> expected6 = {3};  // potions >= 5: 5,7,9
    EXPECT_EQ(expected6, s.successfulPairs(spells6, potions6, 5));
}
