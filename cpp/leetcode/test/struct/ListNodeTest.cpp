#include <boost/test/unit_test.hpp>
#include "struct/ListNode.hpp"

BOOST_AUTO_TEST_CASE(list_node_test) {
    ListNode ln2(2), tbt(1, &ln2);
    BOOST_CHECK_EQUAL(1, tbt.val);
    BOOST_CHECK_EQUAL(2, tbt.next->val);
}
