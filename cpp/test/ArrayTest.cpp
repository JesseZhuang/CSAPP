#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <typeinfo>
#include "string.h"
#include <string>

BOOST_AUTO_TEST_SUITE(array_tests)

    BOOST_AUTO_TEST_CASE(value_init) {
        // default init, outside of function to zero, inside function are uninitialized
        const unsigned size = 5;
        int ia2[size] = {0, 1, 2}; // remaining are value initialized with zero for int array
        BOOST_CHECK_EQUAL(0, ia2[3]);
    }

    BOOST_AUTO_TEST_CASE(array_size) {
        int ia1[] = {0, 1, 2};
        BOOST_CHECK_EQUAL(3, sizeof(ia1) / sizeof(int));
        BOOST_CHECK_EQUAL(3, std::end(ia1) - std::begin(ia1));
        BOOST_CHECK_EQUAL(3, *(&ia1 + 1) - ia1); // next memory location
    }

    BOOST_AUTO_TEST_CASE(char_array_init) {
        char a1[] = "C++";
        BOOST_CHECK_EQUAL(4, sizeof(a1) / sizeof(char));
        BOOST_CHECK_EQUAL('\0', a1[3]);
    }

    BOOST_AUTO_TEST_CASE(auto_decltype) {
        int a[] = {1, 2, 3};
        auto p1(a);
        p1 = &a[0];
        BOOST_CHECK_EQUAL(p1, a);
        BOOST_TEST_MESSAGE("p1 type: " << typeid(p1).name()); // Pi
        decltype(a) ia1 = {1, 2};
        BOOST_TEST_MESSAGE("ia1 type: " << typeid(ia1).name()); // A3_i
    }

    BOOST_AUTO_TEST_CASE(pointer_arithmetic) {
        int a[] = {1, 2, 35};
        BOOST_CHECK_EQUAL(35, *(a + 2));
        BOOST_CHECK_EQUAL(3, *a + 2);
        int *pa3 = &a[3];
        BOOST_CHECK_EQUAL(1, pa3[-3]); // built in subscript operator is not unsigned
    }

    // https://stackoverflow.com/questions/18688971/c-char-array-initialization-what-happens-if-there-are-less-characters-in-the-st
    // cstring header, in cpp, string.h
    BOOST_AUTO_TEST_CASE(c_style_string_functions) {
        char ca[] = {'C', '+', '+', '\0'};
        BOOST_CHECK_EQUAL(3, strlen(ca)); // count length till '\0' null character
        char ca2[] = {'c', '\0'};
        BOOST_CHECK(strcmp(ca, ca2) < 0); // C 67 c 99
        BOOST_CHECK_EQUAL(4, strlen(strcat(ca, ca2))); // appends ca2 to ca
        BOOST_CHECK_EQUAL(1, strlen(strcpy(ca, ca2))); // copies ca2 to ca and returns ca
    }

    BOOST_AUTO_TEST_CASE(string_compare) {
        using namespace std;
        string s1 = "a string", s2 = "a different string";
        BOOST_CHECK(s1 > s2);
        const char ca1[] = "a string", ca2[] = "a different string";
        BOOST_CHECK(strcmp(ca1, ca2) > 0); // cannot directly compare ca1 ca2, unrelated addresses
        cout << "address ca1: " << (void *) ca1 << endl; // 0x7ff7b7e4e620
        cout << "address ca1: " << (void *) ca2 << endl; // 0x7ff7baea9710
    }

BOOST_AUTO_TEST_SUITE_END()
