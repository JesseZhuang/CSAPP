#include "Bar.hpp"
#include <iostream>

Bar::Bar(std::string s) : bar_(s)
{
    // constructor
}

std::string Bar::get()
{
    std::cout << "test";
    return bar_;
}

void Bar::put(std::string &text)
{
    bar_ = text;
}
