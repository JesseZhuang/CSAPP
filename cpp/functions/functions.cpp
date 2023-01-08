#include <iostream>
#include <vector>

using namespace std;

void passValue(vector<int> vec)
{
    vec.push_back(30);
}

void passRef(vector<int> &vec)
{
    vec.push_back(30);
}

void printVec(vector<int> &vec)
{
    for (auto &i : vec)
        cout << i << " ";
    cout << endl;
}

struct demo
{
    int a;
};

int main()
{
    vector<int> v1{10, 20};
    passValue(v1);
    printVec(v1);
    passRef(v1);
    printVec(v1);

    // compare reference and pointer
    int x = 5, y = 6;
    demo d;
    int *p;
    p = &x;                          // p is address of x
    cout << p << " " << &x << endl;  // 0x7ff7bcab05b8 0x7ff7bcab05b8
    cout << &p << " " << &x << endl; // 0x7ff7bcab05a8 0x7ff7bcab05b8
    // https://stackoverflow.com/questions/10087113/how-many-levels-of-pointers-can-we-have
    p = &y; // 1. Pointer reintialization allowed
    int &r = x;
    cout << p << '\n'; // 6. Prints the address 0x7ff7b127c5b4
    cout << r << '\n'; // 6. Print the value of x
    // &r = y; // 1. Compile Error, c++ reference cannot change to point to something else
    r = y; // 1. x value becomes 6
    p = NULL;
    // &r = NULL; // 2. Compile Error
    p++;                             // 3. Points to next memory location
    r++;                             // 3. x values becomes 7
    cout << p << " " << &x << '\n';  // 4. Different address 0x4 0x7ff7b127c5b8
    cout << &r << " " << &x << '\n'; // 4. Same address 0x7ff7b127c5b8 0x7ff7b127c5b8
    demo *dp = &d;
    demo &qq = d;
    dp->a = 8;
    qq.a = 8;
    return 0;
}
