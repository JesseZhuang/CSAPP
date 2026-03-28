#include "gtest/gtest.h"
#include "dp/ShoppingOffers.hpp"

#include <vector>

using namespace std;

TEST(dp, shopping_offers) {
    Solution sol;

    vector<int> p1{2, 5};
    vector<vector<int>> sp1{{3, 0, 5}, {1, 2, 10}};
    vector<int> n1{3, 2};
    ASSERT_EQ(14, sol.shoppingOffers(p1, sp1, n1));
    ASSERT_EQ(14, sol.shoppingOffers2(p1, sp1, n1));

    vector<int> p2{2, 3, 4};
    vector<vector<int>> sp2{{1, 1, 0, 4}, {2, 2, 1, 9}};
    vector<int> n2{1, 2, 1};
    ASSERT_EQ(11, sol.shoppingOffers(p2, sp2, n2));
    ASSERT_EQ(11, sol.shoppingOffers2(p2, sp2, n2));

    vector<int> p3{1, 2, 3};
    vector<vector<int>> sp3{};
    vector<int> n3{3, 2, 1};
    ASSERT_EQ(10, sol.shoppingOffers(p3, sp3, n3));
    ASSERT_EQ(10, sol.shoppingOffers2(p3, sp3, n3));

    vector<int> p4{10, 20};
    vector<vector<int>> sp4{{1, 1, 5}};
    vector<int> n4{0, 0};
    ASSERT_EQ(0, sol.shoppingOffers(p4, sp4, n4));
    ASSERT_EQ(0, sol.shoppingOffers2(p4, sp4, n4));

    vector<int> p5{5};
    vector<vector<int>> sp5{{2, 8}};
    vector<int> n5{4};
    ASSERT_EQ(16, sol.shoppingOffers(p5, sp5, n5));
    ASSERT_EQ(16, sol.shoppingOffers2(p5, sp5, n5));

    vector<int> p6{1, 1};
    vector<vector<int>> sp6{{1, 1, 5}};
    vector<int> n6{2, 2};
    ASSERT_EQ(4, sol.shoppingOffers(p6, sp6, n6));
    ASSERT_EQ(4, sol.shoppingOffers2(p6, sp6, n6));

    vector<int> p7{4, 3};
    vector<vector<int>> sp7{{2, 1, 5}};
    vector<int> n7{4, 2};
    ASSERT_EQ(10, sol.shoppingOffers(p7, sp7, n7));
    ASSERT_EQ(10, sol.shoppingOffers2(p7, sp7, n7));

    vector<int> p8{10, 10};
    vector<vector<int>> sp8{{1, 1, 1}};
    vector<int> n8{1, 1};
    ASSERT_EQ(1, sol.shoppingOffers(p8, sp8, n8));
    ASSERT_EQ(1, sol.shoppingOffers2(p8, sp8, n8));

    vector<int> p9{3};
    vector<vector<int>> sp9{{2, 5}};
    vector<int> n9{6};
    ASSERT_EQ(15, sol.shoppingOffers(p9, sp9, n9));
    ASSERT_EQ(15, sol.shoppingOffers2(p9, sp9, n9));

    vector<int> p10{2, 3};
    vector<vector<int>> sp10{{1, 0, 1}, {0, 1, 2}, {1, 1, 3}};
    vector<int> n10{2, 2};
    ASSERT_EQ(6, sol.shoppingOffers(p10, sp10, n10));
    ASSERT_EQ(6, sol.shoppingOffers2(p10, sp10, n10));

    vector<int> p11{5, 5, 5};
    vector<vector<int>> sp11{{1, 1, 1, 10}};
    vector<int> n11{1, 1, 1};
    ASSERT_EQ(10, sol.shoppingOffers(p11, sp11, n11));
    ASSERT_EQ(10, sol.shoppingOffers2(p11, sp11, n11));
}
