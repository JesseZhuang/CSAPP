#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::string, std::cin, std::cout, std::endl, std::vector;

void capFirst(string &s) // must pass in mutable type, otherwise the passed in copy is changed, not the original
{                        // must declare before main
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }
}

int main() {
    string s1;      // default init to empty string
    string s2 = s1; // new object, must create a new copy of s1
    // adress of s1: 0x7ff7b7690648, s2: 0x7ff7b7690630
    cout << "adress of s1: " << &s1 << ", s2: " << &s2 << endl;
    string s3 = "hello"; // copy init
    const char *s3p = s3.c_str(); // pointer to a null terminated c char array, mutable
    cout << "print with pointer to s3: " << s3p << endl;
    string s5("hello");  // copy init
    string s4(10, 'c');  // direct init 'cccc_cccc_cc'

    cin >> s1; // white space separated
    cout << s1 << ", " << s2 << endl;
    while (getline(cin, s2)) // ctrl+d for end of input
        if (!s2.empty() && s2.size() < 10) // white space considered empty
            cout << s2 << endl;
    auto s2_len = s2.size();
    cout << "unsigned less than negative: " << std::boolalpha << (s2_len < -1) << endl; // compare int with unsigned

    s3[2] = 'L'; // [] subscript operator
    cout << s3 << endl;
    cout << "print with pointer to s3: " << s3p << endl;
    s5 = "Hello World!!!!!";
    string::size_type punct_count = 0; // decltype(s5.size())
    for (auto c: s5)
        if (ispunct(c))
            ++punct_count;
    cout << punct_count << " punctuation chars in " << s5 << endl;
    for (auto &c: s5) // range for
        c = toupper(c);
    cout << s5 << endl;
    string &s6 = s3;
    cout << "before capFirst: " << s6 << endl;
    capFirst(s3);
    cout << "after capFirst s6: " << s6 << endl;
    cout << "after capFirst s3: " << s3 << endl;

    vector<string> text{"line1: w ", "line2", "", "line4; not empty"};
    for (auto it = text.cbegin(); it != text.cend(); ++it)
        if (!it->empty()) // it->empty() same to (*it).empty()
            cout << *it << endl;
}
