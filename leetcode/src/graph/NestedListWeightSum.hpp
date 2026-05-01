#pragma once
#include <vector>
#include <variant>
#include <numeric>

using namespace std;

// Nested integer representation for testing
struct NestedInteger {
    variant<int, vector<NestedInteger>> data;

    NestedInteger(int val) : data(val) {}
    NestedInteger(vector<NestedInteger> list) : data(std::move(list)) {}

    bool isInteger() const { return holds_alternative<int>(data); }
    int getInteger() const { return get<int>(data); }
    const vector<NestedInteger> &getList() const { return get<vector<NestedInteger>>(data); }
};

// leet 339, DFS. O(n) time, O(d) space where d = max depth.
class SolutionNestedListWeightSum {
public:
    int depthSum(const vector<NestedInteger> &nestedList) {
        return dfs(nestedList, 1);
    }

private:
    int dfs(const vector<NestedInteger> &list, int depth) {
        int res = 0;
        for (const auto &ni : list) {
            if (ni.isInteger()) res += ni.getInteger() * depth;
            else res += dfs(ni.getList(), depth + 1);
        }
        return res;
    }
};
