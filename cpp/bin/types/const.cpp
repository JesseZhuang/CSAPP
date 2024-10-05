#include <iostream>
#include "const_extern.hpp"

int main()
{
    // top-level const int ci
    std::cout << "use const defined in another file: " << ci << std::endl;
    int i = 23;
    // const ref declaration, always low-level
    const int &r1 = i;
    int &r2 = i;
    std::cout << "can use const ref r1 to refer but not change the object: " << r1 << std::endl;
    r2 = 24;
    std::cout << "yet i can be changed with another non const ref: " << r1 << std::endl;
    // bind reference to a different type
    double dval = 2.3;
    const int &ri = dval;
    std::cout << "dval: " << dval << std::endl;
    std::cout << "equivalaent to const int bin = dval first " << ri << std::endl;
    // const pointer
    int errCode = 502;
    int *const curErr = &errCode; // curErr will alwasy point to that address, top-level const pointer
    const double pi = 3.14159;
    const double *const ppi = &pi; // const pointer to a const object, low-level const
    if (*curErr)
    {
        // handle error and reset error code to 0
        *curErr = 0;
    }
    const int *p2 = &ci;
    const int *const p3 = &ci; // p2, p3 same low-level const
    p2 = p3;                   // ok, in general, can convernt non-const to const but not the other way round
    return *curErr;            // echo $? to check return code
}
