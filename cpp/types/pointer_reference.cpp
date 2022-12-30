#include <iostream>
#include <cstdlib> # NULL

int main()
{
    // 3 ways to a null pointer
    int *p1 = 0;
    int *p2 = NULL; // cstdlib preprocessor, mordern cpp should use nullptr
    int *p3 = nullptr;
    /*
     * Pointer states:
     * 1, point to an object, int *p = 2 does not compile
     * 2, point to an location past the end of an object
     * 3, a null pointer, not bound
     * 4, invalid pointer
     */
    int i = 23;
    int &r = i; // r is a reference bound to i and cannot be changed to refrence other objects
    p2 = &i;    // p2 was null pointer, now hold address of i
    int *p4;    // uinitialized pointer
    p4 = p2;    // p4 now hold same adderss as p2
    std::cout << "pointers are equal when they point to same address: " << (p4 == p2) << std::endl;
    std::cout << "pointers are not equal when they point to different address: " << (p4 == p1) << std::endl;
    p2 = 0; // p2 now addresses no object
    // pointer in conditions
    if (!p2)
        std::cout << "null pointer is valid, condition evaluates as false" << std::endl;
    if (p4)
        std::cout << "pointer in condition evaluates the object it points to" << std::endl;
    std::cout << "null pointers are equal: " << (p1 == p2) << std::endl;
    // pointer to pointer
    // https://stackoverflow.com/questions/897366/how-do-pointer-to-pointers-work-in-c-and-when-might-you-use-them
    int **p5 = &p4;
    std::cout << "direct value: " << i << std::endl;
    std::cout << "doubly indirect: " << **p5 << std::endl;
    int *&r2 = p4; // r is a reference to pointer p4, reference is not an object, cannot have pointer to a reference
    *r2 = 24;
    std::cout << "changed value through pointer reference: " << *r2 << std::endl;
}
