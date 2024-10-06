#include "gtest/gtest.h"

using namespace std;

pair<int, int> fibonacci(int n) {
    int depth = 0; // lambda & captured all variables including n and depth
    function<pair<int, int>(int)> dfs = [&](int i) {
        if (i < 0) throw invalid_argument("Invalid input");
        if (i == 0) return pair{0, 0};
        if (i == 1 || i == 2) return pair{0, 1};
        auto [d1, res1] = dfs(i - 1);
        auto [d2, res2] = dfs(i - 2);
        depth = 1 + max(d1, d2); // can modify depth outside of lambda
        return pair{depth, res1 + res2};
    };
    return dfs(n);
}

TEST(function, lamnda_inside_function) {
    ASSERT_EQ(fibonacci(0), (pair{0, 0}));
    ASSERT_EQ(fibonacci(1), (pair{0, 1}));
    ASSERT_EQ(fibonacci(2), (pair{0, 1}));
    ASSERT_EQ(fibonacci(3), (pair{1, 2}));
    ASSERT_EQ(fibonacci(4), (pair{2, 3}));
    ASSERT_EQ(fibonacci(5), (pair{3, 5}));
}
