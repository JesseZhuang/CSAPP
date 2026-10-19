#include "gtest/gtest.h"
#include "dp/QuestionsBrainpower.hpp"

#include <vector>

using namespace std;

TEST(QuestionsBrainpowerTest, OfficialExamples) {
    Solution solution;
    vector<vector<int>> first = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    vector<vector<int>> second = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

    EXPECT_EQ(5LL, solution.mostPoints(first));
    EXPECT_EQ(7LL, solution.mostPoints(second));
}

TEST(QuestionsBrainpowerTest, SingleQuestion) {
    Solution solution;
    vector<vector<int>> questions = {{42, 1}};

    EXPECT_EQ(42LL, solution.mostPoints(questions));
}

TEST(QuestionsBrainpowerTest, SolveOrSkip) {
    Solution solution;
    vector<vector<int>> solve = {{10, 1}, {2, 1}, {1, 1}, {1, 1}};
    vector<vector<int>> skip = {{1, 2}, {10, 1}, {1, 1}, {10, 1}};

    EXPECT_EQ(11LL, solution.mostPoints(solve));
    EXPECT_EQ(20LL, solution.mostPoints(skip));
}

TEST(QuestionsBrainpowerTest, JumpPastEnd) {
    Solution solution;
    vector<vector<int>> questions = {{9, 100000}, {3, 1}, {4, 1}};

    EXPECT_EQ(9LL, solution.mostPoints(questions));
}

TEST(QuestionsBrainpowerTest, MaximumLengthAndPoints) {
    Solution solution;
    vector<vector<int>> questions(100000, {100000, 1});

    EXPECT_EQ(5000000000LL, solution.mostPoints(questions));
}
