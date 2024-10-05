#include <iostream>

int main()
{
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; // const int
    decltype(cj) y = x; // const int& bound to x
    // decltype(cj) z; ref must be initialized
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b;           // uninitialized int
    std::cout << b << std::endl; // undefined, prints out whatever in the reserved memory location
    // decltype(*p) c; c is int& and must be initialized
    decltype(i) e; // uninitialized int
    // decltype((i)) d; int& must be initialized
    return 0;
}
