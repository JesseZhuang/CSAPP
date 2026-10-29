#pragma once

#include <array>
#include <queue>
#include <vector>

using namespace std;

namespace NumberOfStudentsUnableToEatLunch {

class Solution {
public:
    // O(n) time and O(1) auxiliary space.
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        array<int, 2> remaining{};
        for (int student : students) {
            ++remaining[student];
        }

        for (int sandwich : sandwiches) {
            if (remaining[sandwich] == 0) {
                return remaining[1 - sandwich];
            }
            --remaining[sandwich];
        }
        return 0;
    }

    // O(n^2) time in the worst case and O(n) auxiliary space.
    int countStudentsQueue(vector<int>& students, vector<int>& sandwiches) {
        queue<int> waiting(students.begin(), students.end());
        size_t sandwichIndex = 0;
        size_t rotationsWithoutEating = 0;

        while (!waiting.empty() && rotationsWithoutEating < waiting.size()) {
            if (waiting.front() == sandwiches[sandwichIndex]) {
                waiting.pop();
                ++sandwichIndex;
                rotationsWithoutEating = 0;
            } else {
                waiting.push(waiting.front());
                waiting.pop();
                ++rotationsWithoutEating;
            }
        }
        return static_cast<int>(waiting.size());
    }
};

}  // namespace NumberOfStudentsUnableToEatLunch
