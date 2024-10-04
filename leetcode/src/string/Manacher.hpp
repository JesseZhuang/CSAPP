#ifndef MANACHER_HPP
#define MANACHER_HPP
#include <vector>

using namespace std;

class Manacher {
public:
    vector<int> p;
    vector<char> t;
    string s;
    int mppl;

    explicit Manacher(string s);

    string longestPalindromeSubstring();

    int cntPalindromeSubstrings();
};


#endif //MANACHER_HPP
