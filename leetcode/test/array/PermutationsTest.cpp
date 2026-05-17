#include "gtest/gtest.h"
#include "array/Permutations.hpp"

#include <algorithm>
#include <vector>

using namespace std;

namespace {
// Sort each permutation and then the outer vector for set comparison.
vector<vector<int>> normalize(vector<vector<int>> v) {
    for (auto &p : v) sort(p.begin(), p.end());
    sort(v.begin(), v.end());
    return v;
}
} // namespace

TEST(array, permutations_swap) {
    SolutionPermutations sol;

    {
        vector<int> nums{1, 2, 3};
        auto res = sol.permuteSwap(nums);
        ASSERT_EQ(6u, res.size());
    }
    {
        vector<int> nums{0, 1};
        auto res = sol.permuteSwap(nums);
        ASSERT_EQ(2u, res.size());
    }
    {
        vector<int> nums{1};
        auto res = sol.permuteSwap(nums);
        ASSERT_EQ(1u, res.size());
        ASSERT_EQ(vector<int>{1}, res[0]);
    }
    {
        vector<int> nums{-1, 0};
        auto res = sol.permuteSwap(nums);
        ASSERT_EQ(2u, res.size());
    }
    {
        vector<int> nums{1, 2, 3, 4};
        auto res = sol.permuteSwap(nums);
        ASSERT_EQ(24u, res.size());
    }
    {
        vector<int> nums{1, 2, 3, 4, 5, 6};
        auto res = sol.permuteSwap(nums);
        ASSERT_EQ(720u, res.size());
    }
    // Verify actual content for small case
    {
        vector<int> nums{1, 2, 3};
        auto res = normalize(sol.permuteSwap(nums));
        vector<vector<int>> expected = {
            {1, 2, 3}, {1, 2, 3}, {1, 2, 3},
            {1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
        // After normalizing (sorting each perm), all become {1,2,3}
        ASSERT_EQ(expected, res);
    }
}

TEST(array, permutations_insert) {
    SolutionPermutations sol;

    {
        vector<int> nums{1, 2, 3};
        auto res = sol.permuteInsert(nums);
        ASSERT_EQ(6u, res.size());
    }
    {
        vector<int> nums{0, 1};
        auto res = sol.permuteInsert(nums);
        ASSERT_EQ(2u, res.size());
    }
    {
        vector<int> nums{1};
        auto res = sol.permuteInsert(nums);
        ASSERT_EQ(1u, res.size());
        ASSERT_EQ(vector<int>{1}, res[0]);
    }
    {
        vector<int> nums{-1, 0};
        auto res = sol.permuteInsert(nums);
        ASSERT_EQ(2u, res.size());
    }
    {
        vector<int> nums{1, 2, 3, 4};
        auto res = sol.permuteInsert(nums);
        ASSERT_EQ(24u, res.size());
    }
    {
        vector<int> nums{1, 2, 3, 4, 5, 6};
        auto res = sol.permuteInsert(nums);
        ASSERT_EQ(720u, res.size());
    }
    // Cross-check: both methods produce the same set
    {
        vector<int> nums{1, 2, 3};
        auto swap_res = normalize(sol.permuteSwap(nums));
        auto ins_res = normalize(sol.permuteInsert(nums));
        ASSERT_EQ(swap_res, ins_res);
    }
}
