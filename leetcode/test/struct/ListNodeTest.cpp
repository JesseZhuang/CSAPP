#include "gtest/gtest.h"
#include "struct/ListNode.hpp"

TEST(struct, list_node) {
    ListNode ln2(2), tbt(1, &ln2);
    ASSERT_EQ(1, tbt.val);
    ASSERT_EQ(2, tbt.next->val);
}
