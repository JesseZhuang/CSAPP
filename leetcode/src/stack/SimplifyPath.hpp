#ifndef SIMPLIFY_PATH_HPP
#define SIMPLIFY_PATH_HPP

#include <string>
#include <vector>
#include <sstream>

using namespace std;

// LeetCode 71, medium, tags: string, stack.
class SimplifyPath {
public:
    // Stack approach. O(n) time, O(n) space.
    static string simplifyPath(const string &path) {
        vector<string> stack; // O(n) space
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) { // O(n) time
            if (part == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (!part.empty() && part != ".") {
                stack.push_back(part);
            }
        }
        string result;
        for (const auto &dir : stack) result += "/" + dir;
        return result.empty() ? "/" : result;
    }
};

#endif
