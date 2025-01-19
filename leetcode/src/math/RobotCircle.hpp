#ifndef LEETCODE_ROBOTCIRCLE_HPP
#define LEETCODE_ROBOTCIRCLE_HPP

#include <string>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        int dirs[4][2] = {{0,  1},
                          {1,  0},
                          {0,  -1},
                          {-1, 0}}; // clockwise
        for (auto &c: instructions) {
            if (c == 'G') x += dirs[i][0], y += dirs[i][1];
            else if (c == 'R') i = (i + 1) % 4;
            else i = (i + 3) % 4;
        }
        return x == 0 && y == 0 || i > 0;
    }
};

#endif //LEETCODE_ROBOTCIRCLE_HPP
