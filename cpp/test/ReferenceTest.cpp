#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(reference_test)

    BOOST_AUTO_TEST_CASE(swap_reference_swap_pointer)
    {
        int a = 1, b = 2, &ra = a, &rb = b, *pa = &a, *pb = &b;
        BOOST_CHECK_EQUAL(&ra, &a); // reference ra always point to a
        BOOST_CHECK_EQUAL(&ra, pa);
        BOOST_TEST_MESSAGE("ra address: " << &ra << " val: " << a);
        std::swap(ra, rb);
        BOOST_CHECK_EQUAL(ra, 2);
        BOOST_CHECK_EQUAL(rb, 1);
        BOOST_CHECK_EQUAL(&ra, &a);
        BOOST_TEST_MESSAGE("ra address: " << &ra << " v " << pa); // address does not change after swapping
    }

BOOST_AUTO_TEST_SUITE_END()
