#include "deque/NumberOfStudentsUnableToEatLunch.hpp"
#include <gtest/gtest.h>

namespace NumberOfStudentsUnableToEatLunch {
namespace {

void expectUnableToEat(vector<int> students, vector<int> sandwiches, int expected) {
    Solution sol;
    EXPECT_EQ(expected, sol.countStudents(students, sandwiches));
    EXPECT_EQ(expected, sol.countStudentsQueue(students, sandwiches));
}

}  // namespace

TEST(deque, number_of_students_unable_to_eat_lunch_examples) {
    expectUnableToEat({1, 1, 0, 0}, {0, 1, 0, 1}, 0);
    expectUnableToEat({1, 1, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 1}, 3);
}

TEST(deque, number_of_students_unable_to_eat_lunch_every_student_eats_same_type) {
    expectUnableToEat({0, 0, 0}, {0, 0, 0}, 0);
    expectUnableToEat({1, 1}, {1, 1}, 0);
}

TEST(deque, number_of_students_unable_to_eat_lunch_first_sandwich_has_no_match) {
    expectUnableToEat({0, 0, 0}, {1, 0, 0}, 3);
}

TEST(deque, number_of_students_unable_to_eat_lunch_late_exhaustion) {
    expectUnableToEat({0, 1, 0, 1}, {0, 1, 1, 1}, 1);
}

TEST(deque, number_of_students_unable_to_eat_lunch_single_student) {
    expectUnableToEat({0}, {0}, 0);
    expectUnableToEat({0}, {1}, 1);
}

TEST(deque, number_of_students_unable_to_eat_lunch_rotations_before_match) {
    expectUnableToEat({1, 1, 0}, {0, 1, 1}, 0);
}

}  // namespace NumberOfStudentsUnableToEatLunch
