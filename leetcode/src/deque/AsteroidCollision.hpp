#ifndef LEETCODE_ASTEROIDCOLLISION_HPP
#define LEETCODE_ASTEROIDCOLLISION_HPP

#include <vector>
#include <stack>

using namespace std;

class Solution735 {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> st;
        for (int i = 0; i < static_cast<int>(asteroids.size()); i++) { // O(n)
            int asteroid = asteroids[i];
            bool destroyed = false;

            // Handle collisions: only when stack has right-moving and current is left-moving
            while (!st.empty() && st.top() > 0 && asteroid < 0) { // O(n) total
                if (st.top() < -asteroid) {
                    // Current asteroid destroys top
                    st.pop();
                    continue;
                } else if (st.top() == -asteroid) {
                    // Both destroyed
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid destroyed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroid);
            }
        }

        // Convert stack to result vector
        vector<int> res(st.size());
        for (int i = static_cast<int>(st.size()) - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res; // Time O(n), Space O(n)
    }
};

#endif //LEETCODE_ASTEROIDCOLLISION_HPP
