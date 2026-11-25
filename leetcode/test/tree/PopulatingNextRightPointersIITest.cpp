#include "gtest/gtest.h"
#include "tree/PopulatingNextRightPointersII.hpp"

namespace {
using populating_next_right_pointers_ii::Node;
using populating_next_right_pointers_ii::Solution;

void expectNextRightPointers(Node *(Solution::*connect)(Node *)) {
    Solution solution;
    EXPECT_EQ(nullptr, (solution.*connect)(nullptr));

    Node single{1};
    EXPECT_EQ(&single, (solution.*connect)(&single));
    EXPECT_EQ(nullptr, single.next);

    Node eight{8};
    Node nine{9};
    Node four{4, nullptr, &eight};
    Node five{5};
    Node seven{7, &nine};
    Node two{2, &four, &five};
    Node three{3, nullptr, &seven};
    Node root{1, &two, &three};

    EXPECT_EQ(&root, (solution.*connect)(&root));
    EXPECT_EQ(nullptr, root.next);
    EXPECT_EQ(&three, two.next);
    EXPECT_EQ(nullptr, three.next);
    EXPECT_EQ(&five, four.next);
    EXPECT_EQ(&seven, five.next);
    EXPECT_EQ(nullptr, seven.next);
    EXPECT_EQ(&nine, eight.next);
    EXPECT_EQ(nullptr, nine.next);

    Node leaf{3};
    Node child{2, nullptr, &leaf};
    Node oneSided{1, nullptr, &child};
    EXPECT_EQ(&oneSided, (solution.*connect)(&oneSided));
    EXPECT_EQ(nullptr, oneSided.next);
    EXPECT_EQ(nullptr, child.next);
    EXPECT_EQ(nullptr, leaf.next);
}
}

TEST(tree, populating_next_right_pointers_ii_bfs) {
    expectNextRightPointers(&Solution::connect);
}

TEST(tree, populating_next_right_pointers_ii_constant_space) {
    expectNextRightPointers(&Solution::connectConstantSpace);
}
