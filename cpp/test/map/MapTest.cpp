#include "gtest/gtest.h"
#include <unordered_map>
#include <set>
#include <ranges>

using namespace std;

// google test fixture
class MapTestF : public ::testing::Test {
public:
    unordered_map<int, int> tbt{};
};

TEST_F(MapTestF, collect_values_to_set) {
    tbt.insert(make_pair(1, 1));
    tbt.insert(make_pair(2, 1));
    tbt.insert(make_pair(3, 3));
    tbt.insert(make_pair(4, 4));
    auto kv = views::values(tbt);
    const set<int> uniqV{kv.begin(), kv.end()};
    ASSERT_EQ(uniqV.size(), 3);
    const set expected{1, 3, 4};
    ASSERT_EQ(expected, uniqV);
    ASSERT_EQ(kv.size(), tbt.size()); // of course, map size == key set size == value list size
    ASSERT_EQ(tbt.size() - 1, expected.size()); // one duplicate value 1:1, 2:1
}

TEST_F(MapTestF, bracket_opperator) {
    ASSERT_TRUE(tbt.empty());
    ASSERT_EQ(0, tbt[1]); // inserted with default value 0, on first time access
    ASSERT_EQ(1, tbt.size());
    tbt[1] += 10; // can increment
    ASSERT_EQ(10, tbt[1]);
    unordered_map<int, string> tbt2{{1, "apple"},
                                    {2, "orange"}};
    ASSERT_EQ(2, tbt2.size());
    ASSERT_EQ("apple", tbt2[1]);
    ASSERT_TRUE(tbt2[3].empty()); // construct default empty string for not existing key
    ASSERT_EQ(3, tbt2.size());
}
