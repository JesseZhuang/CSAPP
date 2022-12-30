#include <iostream>
#include "const_extern.hpp"

int main()
{
    std::cout << "use const defined in another file: " << ci << std::endl;
    int i = 23;
    // const ref declaration
    const int &r1 = i;
    int &r2 = i;
    std::cout << "can use const ref r1 to refer but not change the object: " << r1 << std::endl;
    r2 = 24;
    std::cout << "yet i can be changed with another non const ref: " << r1 << std::endl;
    // bind reference to a different type
    double dval = 2.3;
    const int &ri = dval;
    std::cout << "dval: " << dval << std::endl;
    std::cout << "equivalaent to const int temp = dval first " << ri << std::endl;
}
