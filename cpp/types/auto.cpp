#include <iostream>

int main() {
    auto i = 23, *p = &i; // ok both are int
    // auto sz = 0, pi = 3.24; // not ok
    int i2 = 21, &r = i2;
    auto a = r; // reference type int
    const int ci = i, &cr = ci;
    auto b = ci; // b is int, top level const in ci is dropped
    std::cout << "b before change " << b << std::endl; // 23
    b = 4;
    std::cout << "b after change " << b << std::endl; // 4
    auto c = cr; // int, cr is an alias for ci, top-level dropped
    std::cout << "c before change " << c << std::endl; // 23
    c = 5;
    std::cout << "c after change " << c << std::endl; // 5
    std::cout << "b after c change " << b << std::endl; // 4
    auto d = &i;       // int*
    auto e = &ci;      // const int* low-level is kept
    const auto f = ci; // const int
    auto &g = ci;      // const int& ref
    auto i3(i);        // is same type as i
}
