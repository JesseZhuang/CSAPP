#include <iostream>

int j = 0;
// constexpr since c++11
constexpr int i = 23; // cosnt int

int main()
{
    // const int sz = get_size(); maybe not a const expression, determined at run time
    // constexpr imposes a top-level const
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    // constexpr int sz = size() ok only if size is a constexpr function
    // arithmetic, reference, and pointer types ae literal types
    // class, library IO, and string types are not literal types
    const int *p = nullptr;      // pointer to const
    constexpr int *np = nullptr; // const pointer to null
    // i and j must be decalred outside of any function
    constexpr const int *p1 = &i; // const pointer to const int
    constexpr int *p2 = &j;       // const pointer to int j, points to non-const
    *p2 = 10;
    std::cout << "const pointer points to non-const, can change: " << j << std::endl;
}
