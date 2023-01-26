#include <iostream>
#include <cstdlib> // NULL

void reference_swap() {
    int a = 1, b = 2;
    int &ra = a, &rb = b;
    std::cout << "before swap ra: " << ra << " rb: " << rb << std::endl;
    std::cout << "before swap a: " << a << " b: " << b << std::endl;
    std::swap(ra, rb); // ra still references a after swapping
    std::cout << "after swap ra: " << ra << " rb: " << rb << std::endl;
    std::cout << "after swap a: " << a << " b: " << b << std::endl;
}

int main() {
    // 3 ways to a null pointer
    int *p1 = 0;
    int *p2 = NULL; // cstdlib preprocessor, modern cpp should use nullptr
    int *p3 = nullptr;
    /*
     * Pointer states:
     * 1, point to an object, int *p = 2 does not compile
     * 2, point to an location past the end of an object
     * 3, a null pointer, not bound
     * 4, invalid pointer
     */
    int i = 23;
    int &r = i; // r is a reference bound to i and cannot be changed to reference other objects
    reference_swap();
    p2 = &i;    // p2 was null pointer, now hold address of i
    int *p4;    // uninitialized pointer
    p4 = p2;    // p4 now hold same adders as p2
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
    int array[] = {1, 2, 3, 4, 5};
    std::cout << "arry address starts at " << array << std::endl; // arry address starts at 0x7ff7b7e4e620
    for (int i = 0; i < 6; i++)
        std::cout << "i: " << i << ", array pointer: "
                  << array + i << " value: " << *(array + i) << std::endl;
    // i: 0, array pointer: 0x7ff7b7e4e620 value: 1
    // i: 1, array pointer: 0x7ff7b7e4e624 value: 2
    // i: 2, array pointer: 0x7ff7b7e4e628 value: 3
    // i: 3, array pointer: 0x7ff7b7e4e62c value: 4
    // i: 4, array pointer: 0x7ff7b7e4e630 value: 5
    // i: 5, array pointer: 0x7ff7b7e4e634 value: 0
}
