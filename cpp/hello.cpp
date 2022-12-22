#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "hello world!"
              << "\n";
    std::cout << "arg count: " << argc << std::endl
              << "args: " << argv[0] << ", " << argv[1] << std::endl;
    return 0;
}
