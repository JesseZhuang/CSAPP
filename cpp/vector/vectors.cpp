#include <iostream>
#include <vector>
#include <string>

using std::cin, std::cout, std::endl, std::vector, std::string;

int main()
{
    // vector is class template, hold objects of most any type, refrences are not objects
    // some compilers may require old style declaration vector<vector<int> >
    vector<int> v1(10);     // default init to 0
    vector<string> svec(3); // default init empty strings
    vector<int> v2{10};     // 1 element with value 10
    vector<int> v3(10, 1);  // ten elements with value 1
    vector<int> v4{10, 1};  // two elements
    string word;
    while (cin >> word)
        svec.push_back(word);
    svec.pop_back();
    cout << svec.size() << endl;
    string words;
    if (svec.size() > 0)
        for (auto s : svec)
        {
            words += s;
            words += ",";
        }
    cout << words << endl;
}
