#ifndef LEETCODE_MINSTACK_HPP
#define LEETCODE_MINSTACK_HPP

#include <stack>
#include <algorithm>

using namespace std;

// LeetCode 155, medium, tags: stack, design.
// Two stacks approach. O(1) time for all operations, O(n) space.
class MinStack155 {
    stack<int> st;
    stack<int> minSt; // tracks current min at each level
public:
    MinStack155() {}

    void push(int val) {
        st.push(val); // O(1)
        minSt.push(minSt.empty() ? val : min(val, minSt.top())); // O(1)
    }

    void pop() {
        st.pop(); // O(1)
        minSt.pop(); // O(1)
    }

    int top() {
        return st.top(); // O(1)
    }

    int getMin() {
        return minSt.top(); // O(1)
    }
};

// Single stack with pairs. O(1) time for all operations, O(n) space.
class MinStack155V2 {
    stack<pair<int, int>> st; // stores {val, currentMin}
public:
    MinStack155V2() {}

    void push(int val) {
        int curMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, curMin}); // O(1)
    }

    void pop() {
        st.pop(); // O(1)
    }

    int top() {
        return st.top().first; // O(1)
    }

    int getMin() {
        return st.top().second; // O(1)
    }
};

#endif //LEETCODE_MINSTACK_HPP
