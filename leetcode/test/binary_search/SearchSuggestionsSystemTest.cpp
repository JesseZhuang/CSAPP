#include <gtest/gtest.h>
#include "binary_search/SearchSuggestionsSystem.hpp"

TEST(binary_search, search_suggestions_system) {
    Solution s;

    // Example 1
    vector<string> products1 = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord1 = "mouse";
    vector<vector<string>> expected1 = {
        {"mobile", "moneypot", "monitor"},
        {"mobile", "moneypot", "monitor"},
        {"mouse", "mousepad"},
        {"mouse", "mousepad"},
        {"mouse", "mousepad"}
    };
    EXPECT_EQ(expected1, s.suggestedProducts(products1, searchWord1));

    // Example 2
    vector<string> products2 = {"havana"};
    string searchWord2 = "havana";
    vector<vector<string>> expected2 = {
        {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}
    };
    EXPECT_EQ(expected2, s.suggestedProducts(products2, searchWord2));

    // No match
    vector<string> products3 = {"bags", "baggage", "banner", "box", "cloths"};
    string searchWord3 = "xyz";
    vector<vector<string>> expected3 = {{}, {}, {}};
    EXPECT_EQ(expected3, s.suggestedProducts(products3, searchWord3));

    // Single character searchWord
    vector<string> products4 = {"apple", "apricot", "banana"};
    string searchWord4 = "a";
    vector<vector<string>> expected4 = {{"apple", "apricot"}};
    EXPECT_EQ(expected4, s.suggestedProducts(products4, searchWord4));
}
