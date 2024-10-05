#include <iostream>

int main()
{
    typedef double wages;
    typedef wages base, *p;
    using wages = double;
    typedef char *pstring; // pointer to char
    pstring buffer = new char{};
    std::cout << std::strlen(buffer) << "\n";
    std::cout << sizeof(*buffer) << "\n";
    std::cout << std::boolalpha << (buffer[0] == '\0') << '\n';
    *buffer = 'i';
    std::cout << buffer << std::endl;
    std::cout << sizeof(*buffer) << "\n";
    std::cout << std::boolalpha << (buffer[1] == '\0') << '\n'; // dangerous, accessing memory outside

    const pstring cstr = 0;      // cstr: const pointer to char
    const char *cstr2 = "test2"; // cstr2: pointer to const char
}
