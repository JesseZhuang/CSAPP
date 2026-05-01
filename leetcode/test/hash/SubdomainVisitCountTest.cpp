#include "hash/SubdomainVisitCount.hpp"
#include <gtest/gtest.h>
#include <algorithm>
#include <set>

TEST(hash, subdomain_visit_count) {
    SolutionSubdomainVisitCount sol;

    // Example 1
    vector<string> cp1 = {"9001 discuss.leetcode.com"};
    auto res1 = sol.subdomainVisits(cp1);
    set<string> s1(res1.begin(), res1.end());
    set<string> exp1 = {"9001 leetcode.com", "9001 discuss.leetcode.com", "9001 com"};
    EXPECT_EQ(s1, exp1);

    // Example 2
    vector<string> cp2 = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    auto res2 = sol.subdomainVisits(cp2);
    set<string> s2(res2.begin(), res2.end());
    set<string> exp2 = {"901 mail.com", "50 yahoo.com", "900 google.mail.com",
                        "5 wiki.org", "5 org", "1 intel.mail.com", "951 com"};
    EXPECT_EQ(s2, exp2);
}
