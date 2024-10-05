#include <iostream>

int main()
{
    int sum = 0, val = 0;
    std::cout << "type numbers to sum below, separte by space:" << std::endl;
    while (std::cin >> val)
        sum += val;
    std::cout << "sum is: " << sum << std::endl;
    return 0;
}
