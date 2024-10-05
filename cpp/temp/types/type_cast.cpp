#include <iostream>

using namespace std;

int main() {
    int dx = 3, dy = 1;
    cout << "slope (cast to double): " << static_cast<double> (dy) / dx << endl;
    // useful to convert where compiler will not automatically
    double d = 0.23;
    void *dp = &d;
    cout << "void* address: " << dp << endl;
    cout << "casted double* address: " << static_cast<double *>(dp) << endl; // same as above
    cout << "val of casted double*: " << *static_cast<double *>(dp) << endl;
    string s = "hello";
    const char *pc = s.c_str();
    char *pcm = const_cast<char *>(pc); // original object cannot be const, writing to a const object is undefined
    pcm[0] = 'H';
    cout << "string changed: " << s << endl;
    // const cast most useful in the context of overloaded functions
    int neg_one = 0xffffffff;
    cout << "signed int -1: " << neg_one << endl;
    cout << "cast to unsigned: " << reinterpret_cast<unsigned int &>(neg_one) << endl; // 4294967295 == 2^32 - 1
    unsigned int max = (unsigned int) neg_one;
    cout << "old c style cast: " << max << endl;
}
