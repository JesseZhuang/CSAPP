#include "dp/JumpGameVI.hpp"
#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

namespace {
void verify(const vector<int>& nums, int k, int expected) {
    JumpGameVI sol;
    EXPECT_EQ(expected, sol.maxResult(nums, k)) << "deque, k=" << k;
    EXPECT_EQ(expected, sol.maxResultHeap(nums, k)) << "heap, k=" << k;
}

int bruteForce(const vector<int>& nums, int k) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    for (int index = 1; index < (int)nums.size(); ++index) {
        int best = dp[index - 1];
        for (int previous = max(0, index - k); previous < index; ++previous) {
            best = max(best, dp[previous]);
        }
        dp[index] = best + nums[index];
    }
    return dp.back();
}
}

TEST(dp, jump_game_vi_examples) {
    verify({1, -1, -2, 4, -7, 3}, 2, 7);
    verify({10, -5, -2, 4, 0, 3}, 3, 17);
    verify({1, -5, -20, 4, -1, 3, -6, -3}, 2, 0);
}

TEST(dp, jump_game_vi_single_element) {
    verify({-10000}, 1, -10000);
    verify({10000}, 100000, 10000);
}

TEST(dp, jump_game_vi_forced_adjacent_jumps) {
    verify({-5, -2, -9, -1}, 1, -17);
    verify({3, 0, 4, -5, 2}, 1, 4);
}

TEST(dp, jump_game_vi_negative_plateau) {
    verify({-5, -1, -1, -1, -5}, 2, -11);
    verify({0, 0, 0, 0, 0, 0}, 2, 0);
}

TEST(dp, jump_game_vi_expired_maximum) {
    verify({10, 100, -1000, -1000, -1000, 1}, 2, -889);
    verify({1, -100, 2, 100, -100, 3}, 2, 106);
}

TEST(dp, jump_game_vi_large_jump_window) {
    verify({5, -100, 3, 4}, 100000, 12);
    verify({-5, -10, -2}, 3, -7);
}

TEST(dp, jump_game_vi_large_signed_results) {
    verify(vector<int>(100000, 10000), 100000, 1000000000);
    verify(vector<int>(100000, -10000), 1, -1000000000);
    verify(vector<int>(100000, -10000), 100000, -20000);
}

TEST(dp, jump_game_vi_matches_quadratic_reference) {
    uint32_t state = 1696;
    for (int trial = 0; trial < 100; ++trial) {
        state = state * 1664525u + 1013904223u;
        int length = 1 + (state % 24);
        vector<int> nums(length);
        for (int& value : nums) {
            state = state * 1664525u + 1013904223u;
            value = (int)(state % 21) - 10;
        }
        for (int k = 1; k <= length + 2; ++k) {
            verify(nums, k, bruteForce(nums, k));
        }
    }
}
