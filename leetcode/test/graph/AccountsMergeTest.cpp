#include "gtest/gtest.h"
#include "graph/AccountsMerge.hpp"

#include <algorithm>

using namespace std;

static void sortAccountsForCompare(vector<vector<string>> &v) {
    for (auto &row: v)
        sort(row.begin() + 1, row.end());
    sort(v.begin(), v.end());
}

template <typename Sol>
static void run_accounts_merge_cases() {
    {
        vector<vector<string>> accounts{{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                        {"John", "johnsmith@mail.com", "john00@mail.com"},
                                        {"Mary", "mary@mail.com"},
                                        {"John", "johnnybravo@mail.com"}};
        vector<vector<string>> want{{"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
                                    {"John", "johnnybravo@mail.com"},
                                    {"Mary", "mary@mail.com"}};
        Sol sol;
        auto got = sol.accountsMerge(accounts);
        sortAccountsForCompare(got);
        sortAccountsForCompare(want);
        EXPECT_EQ(want, got);
    }
    {
        vector<vector<string>> accounts{{"Ava", "a1@mail.com", "a2@mail.com"},
                                        {"Ben", "b1@mail.com", "b2@mail.com"},
                                        {"Cal", "c1@mail.com", "c2@mail.com"},
                                        {"Dot", "d1@mail.com", "d2@mail.com"},
                                        {"Eve", "e1@mail.com", "e2@mail.com"}};
        vector<vector<string>> want = accounts;
        Sol sol;
        auto got = sol.accountsMerge(accounts);
        sortAccountsForCompare(got);
        sortAccountsForCompare(want);
        EXPECT_EQ(want, got);
    }
    {
        vector<vector<string>> accounts{{"Alice", "a@m.co"}};
        vector<vector<string>> want{{"Alice", "a@m.co"}};
        Sol sol;
        auto got = sol.accountsMerge(accounts);
        sortAccountsForCompare(got);
        sortAccountsForCompare(want);
        EXPECT_EQ(want, got);
    }
    {
        vector<vector<string>> accounts{{"Bob", "x@m.co"},
                                        {"Bob", "y@m.co"},
                                        {"Bob", "x@m.co", "y@m.co"}};
        vector<vector<string>> want{{"Bob", "x@m.co", "y@m.co"}};
        Sol sol;
        auto got = sol.accountsMerge(accounts);
        sortAccountsForCompare(got);
        sortAccountsForCompare(want);
        EXPECT_EQ(want, got);
    }
    {
        vector<vector<string>> accounts{{"Tom", "t1@m.co"}, {"Tom", "t2@m.co"}};
        vector<vector<string>> want{{"Tom", "t1@m.co"}, {"Tom", "t2@m.co"}};
        Sol sol;
        auto got = sol.accountsMerge(accounts);
        sortAccountsForCompare(got);
        sortAccountsForCompare(want);
        EXPECT_EQ(want, got);
    }
    {
        vector<vector<string>> accounts{{"Ann", "e1@m.co", "e2@m.co"},
                                        {"Ann", "e2@m.co", "e3@m.co"},
                                        {"Ann", "e3@m.co", "e4@m.co"}};
        vector<vector<string>> want{{"Ann", "e1@m.co", "e2@m.co", "e3@m.co", "e4@m.co"}};
        Sol sol;
        auto got = sol.accountsMerge(accounts);
        sortAccountsForCompare(got);
        sortAccountsForCompare(want);
        EXPECT_EQ(want, got);
    }
}

TEST(graph, accounts_merge) {
    run_accounts_merge_cases<lc721::Solution>();
}

TEST(graph, accounts_merge_dfs) {
    run_accounts_merge_cases<lc721::Solution2>();
}
