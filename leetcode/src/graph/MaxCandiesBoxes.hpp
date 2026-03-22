#ifndef MAXCANDIESBOXES_HPP
#define MAXCANDIESBOXES_HPP

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int> &status, vector<int> &candies,
                   vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                   vector<int> &initialBoxes) {
        int n = static_cast<int>(status.size());
        vector<bool> has_box(n, false);
        vector<bool> opened(n, false);
        vector<int> has_key = status;
        int res = 0;
        queue<int> q;
        for (int b : initialBoxes) {
            has_box[b] = true;
            if (has_key[b]) {
                q.push(b);
                opened[b] = true;
            }
        }
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            res += candies[box];
            for (int k : keys[box]) {
                if (!has_key[k]) {
                    has_key[k] = 1;
                    if (has_box[k] && !opened[k]) {
                        opened[k] = true;
                        q.push(k);
                    }
                }
            }
            for (int b : containedBoxes[box]) {
                has_box[b] = true;
                if (!opened[b] && has_key[b]) {
                    opened[b] = true;
                    q.push(b);
                }
            }
        }
        return res;
    }
};

#endif // MAXCANDIESBOXES_HPP
