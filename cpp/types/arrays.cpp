#include "cstddef" // size_t
#include <iostream>

void access_array() {
    const unsigned size = 3;
    int a[size]; // undefined, inside function
    for (size_t i = 0; i < size; ++i) std::cout << a[i] << " ";
    std::cout << std::endl;
    for (auto n: a) std::cout << n << " "; // 1 -1269884608 32759
    std::cout << std::endl;
}

void pointer_iterate() {
    int a[] = {1, 2, 3};
    int *end = &a[3];
    int *end2 = *(&a + 1);
    std::cout << end << " " << end2 << std::endl;
    for (int *pa = a; pa != end; ++pa) std::cout << *pa << " ";
    std::cout << std::endl;
}

int main() {
    access_array();
    pointer_iterate();
}
