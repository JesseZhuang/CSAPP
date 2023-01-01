#include <iostream>
#include <string>
#include <cctype>

using std::string, std::cin, std::cout, std::endl;

int main()
{
    string s1;      // default init to empty string
    string s2 = s1; // new object, must create a new copy of s1
    // adress of s1: 0x7ff7b7690648, s2: 0x7ff7b7690630
    cout << "adress of s1: " << &s1 << ", s2: " << &s2 << endl;
    string s3 = "hello"; // copy init
    string s5("hello");  // copy init
    string s4(10, 'c');  // direct init 'cccc_cccc_cc'

    cin >> s1; // white space separated
    cout << s1 << ", " << s2 << endl;
    while (getline(cin, s2))
        if (!s2.empty() && s2.size() < 10) // white space considered empty
            cout << s2 << endl;
    auto s2_len = s2.size();
    cout << std::boolalpha << (s2_len < -1) << endl; // compare int with unsigned

    s3[2] = 'L'; // [] subscript operator
    cout << s3 << endl;
    s5 = "Hello World!!!!!";
    string::size_type punct_count = 0; // decltype(s5.size())
    for (auto c : s5)
        if (ispunct(c))
            ++punct_count;
    cout << punct_count << " punctuation chars in " << s5 << endl;
    for (auto &c : s5)
        c = toupper(c);
    cout << s5 << endl;
}
