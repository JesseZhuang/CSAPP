#include "gtest/gtest.h"
#include "graph/EvaluateDivision.hpp"

using namespace std;
using namespace lc399;

static void expectNear(const vector<double> &expected, const vector<double> &actual) {
    ASSERT_EQ(expected.size(), actual.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_NEAR(expected[i], actual[i], 1e-5) << "index " << i;
    }
}

// BFS tests
TEST(graph, evaluate_division) {
    Solution sol;

    // Example 1
    {
        vector<vector<string>> equations{{"a", "b"}, {"b", "c"}};
        vector<double> values{2.0, 3.0};
        vector<vector<string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
        vector<double> expected{6.0, 0.5, -1.0, 1.0, -1.0};
        expectNear(expected, sol.calcEquation(equations, values, queries));
    }

    // Example 2
    {
        vector<vector<string>> equations{{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
        vector<double> values{1.5, 2.5, 5.0};
        vector<vector<string>> queries{{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
        vector<double> expected{3.75, 0.4, 5.0, 0.2};
        expectNear(expected, sol.calcEquation(equations, values, queries));
    }

    // Disconnected
    {
        vector<vector<string>> equations{{"a", "b"}, {"c", "d"}};
        vector<double> values{2.0, 3.0};
        vector<vector<string>> queries{{"a", "d"}, {"c", "b"}};
        vector<double> expected{-1.0, -1.0};
        expectNear(expected, sol.calcEquation(equations, values, queries));
    }

    // Chain
    {
        vector<vector<string>> equations{{"a", "b"}, {"b", "c"}, {"c", "d"}, {"d", "e"}};
        vector<double> values{2.0, 3.0, 4.0, 5.0};
        vector<vector<string>> queries{{"a", "e"}, {"e", "a"}};
        vector<double> expected{120.0, 1.0 / 120.0};
        expectNear(expected, sol.calcEquation(equations, values, queries));
    }
}

// Union-Find tests
TEST(graph, evaluate_division_union_find) {
    Solution sol;

    // Example 1
    {
        vector<vector<string>> equations{{"a", "b"}, {"b", "c"}};
        vector<double> values{2.0, 3.0};
        vector<vector<string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
        vector<double> expected{6.0, 0.5, -1.0, 1.0, -1.0};
        expectNear(expected, sol.calcEquationUnionFind(equations, values, queries));
    }

    // Example 2
    {
        vector<vector<string>> equations{{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
        vector<double> values{1.5, 2.5, 5.0};
        vector<vector<string>> queries{{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
        vector<double> expected{3.75, 0.4, 5.0, 0.2};
        expectNear(expected, sol.calcEquationUnionFind(equations, values, queries));
    }

    // Disconnected
    {
        vector<vector<string>> equations{{"a", "b"}, {"c", "d"}};
        vector<double> values{2.0, 3.0};
        vector<vector<string>> queries{{"a", "d"}, {"c", "b"}};
        vector<double> expected{-1.0, -1.0};
        expectNear(expected, sol.calcEquationUnionFind(equations, values, queries));
    }

    // Chain
    {
        vector<vector<string>> equations{{"a", "b"}, {"b", "c"}, {"c", "d"}, {"d", "e"}};
        vector<double> values{2.0, 3.0, 4.0, 5.0};
        vector<vector<string>> queries{{"a", "e"}, {"e", "a"}};
        vector<double> expected{120.0, 1.0 / 120.0};
        expectNear(expected, sol.calcEquationUnionFind(equations, values, queries));
    }
}
