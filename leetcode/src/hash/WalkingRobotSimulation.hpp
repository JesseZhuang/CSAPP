#ifndef LEETCODE_WALKINGROBOTSIMULATION_HPP
#define LEETCODE_WALKINGROBOTSIMULATION_HPP

#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        unordered_set<string> obs;
        for (auto &o : obstacles) {
            obs.insert(to_string(o[0]) + "," + to_string(o[1]));
        }
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0, res = 0;
        for (int c : commands) {
            if (c == -2) {
                d = (d + 3) % 4;
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else {
                for (int i = 0; i < c; i++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (obs.count(to_string(nx) + "," + to_string(ny))) {
                        break;
                    }
                    x = nx;
                    y = ny;
                }
                res = max(res, x * x + y * y);
            }
        }
        return res;
    }
};

#endif // LEETCODE_WALKINGROBOTSIMULATION_HPP
