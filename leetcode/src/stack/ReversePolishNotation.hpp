#pragma once

#include <vector>
#include <string>
#include <stack>

using namespace std;

// O(n) time, O(n) space
class ReversePolishNotation {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(int(a / b)); // C++ int division truncates toward zero
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
