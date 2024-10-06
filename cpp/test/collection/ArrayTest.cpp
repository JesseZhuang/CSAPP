#include <gtest/gtest.h>
#include <typeinfo>
#include <cstring>
#include <string>

using namespace std;

TEST(array, value_init) {
    // default init, outside of function to zero, inside function are uninitialized
    const unsigned size = 5;
    int ia2[size] = {0, 1, 2}; // remaining are value initialized with zero for int array
    ASSERT_EQ(0, ia2[3]);
}

TEST(array, pointer_arithmetic) {
    int a[] = {1, 2, 35};
    ASSERT_EQ(35, *(a + 2));
    ASSERT_EQ(3, *a + 2);
    int *pa3 = &a[3];
    ASSERT_EQ(1, pa3[-3]); // built in subscript operator is not unsigned
}

TEST(array, array_size) {
    int ia1[] = {0, 1, 2};
    ASSERT_EQ(3, sizeof(ia1) / sizeof(int));
    ASSERT_EQ(3, end(ia1) - begin(ia1));
    ASSERT_EQ(3, *(&ia1 + 1) - ia1); // next memory location, double pointer
}

TEST(array, char_array_init) {
    char a1[] = "C++";
    ASSERT_EQ(4, sizeof(a1) / sizeof(char));
    ASSERT_EQ('\0', a1[3]);
}

TEST(array, auto_decltype) {
    int a[] = {1, 2, 3};
    auto p1(a);
    // p1 = &a[0];
    ASSERT_EQ(p1, a);
    cout << "p1 type: " << typeid(p1).name() << endl; // Pi, pointer to int?
    decltype(a) ia1 = {1, 2};
    cout << "ia1 type: " << typeid(ia1).name() << endl; // A3_i array of three int pointer
}

// https://stackoverflow.com/questions/18688971/c-char-array-initialization-what-happens-if-there-are-less-characters-in-the-st
// cstring header, in cpp, string.h
TEST(array, c_style_string_functions) {
    char ca[] = {'C', '+', '+', '\0'};
    ASSERT_EQ(3, strlen(ca)); // count length till '\0' null character
    char ca2[10] = {'c', '\0'}; // rest all 0 == '\0'
    ASSERT_EQ(1, strlen(ca2));
    ASSERT_TRUE(strcmp(ca, ca2) < 0); // C 67 c 99, compare first char
    ASSERT_EQ(4, strlen(strcat(ca, ca2))); // appends ca2 to ca
    ASSERT_EQ(1, strlen(strcpy(ca, ca2))); // copies ca2 to ca and returns ca
}

TEST(array, string_compare) {
    string s1 = "a string", s2 = "a different string";
    ASSERT_TRUE(s1 > s2);
    const char ca1[] = "a string", ca2[] = "a different string";
    ASSERT_TRUE(strcmp(ca1, ca2) > 0); // cannot directly compare ca1 ca2, unrelated addresses
    cout << "address ca1: " << (void *) ca1 << endl; // 0x7ff7b7e4e620
    cout << "address ca1: " << (void *) ca2 << endl; // 0x7ff7baea9710
}


TEST(array, multi_dim_array) {
    constexpr size_t nRow = 3, nCol = 4;
    int ia[nRow][nCol];
    for (size_t i = 0; i != nRow; ++i)
        for (size_t j = 0; j != nCol; ++j)
            ia[i][j] = i * nCol + j;
    ASSERT_EQ(0, ia[0][0]);
    ASSERT_EQ(4, ia[1][0]);
    size_t cnt = 0;
    for (auto &row: ia)
        for (auto &col: row) col = cnt++;
    ASSERT_EQ(0, ia[0][0]);
    ASSERT_EQ(4, ia[1][0]);
}


TEST(array, multi_dim_array_row_pointer) {
    int ia[3][4]; // no default init value
    int (*row1)[4] = ia, (*row2)[4] = &ia[1]; // pointer to an array of 4 ints, first row
    int *ip[4]; // array of pointers to int
    (*row1)[2] = 23, (*row2)[3] = 42; // multiple statement same line, use comma
    ip[2] = &ia[0][2], ip[3] = &ia[1][3]; // can point to elements in different rows
    ASSERT_EQ(23, *ip[2]);
    ASSERT_EQ(42, *ip[3]);
    using int_array = int[4]; // old style: typedef int int_array[4];
    cout << "2d array 3x4 content: " << endl;
    for (int_array *p = ia; p != end(ia); ++p) {
        for (int *q = *p; q != end(*p); ++q)
            cout << *q << ' ';
        cout << endl;
    }
}
