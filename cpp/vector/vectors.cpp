#include <iostream>
#include <vector>
#include <string>
#include <numeric> // iota https://stackoverflow.com/questions/9244879/what-does-iota-of-stdiota-stand-for

using std::cin, std::cout, std::endl, std::vector, std::string;

int binarySearch(vector<int> &vec, int target) // vec must be sorted, pass by reference
{
    auto left = vec.begin(), right = vec.end();
    while (left <= right)
    {
        auto mid = left + (right - left) / 2;
        if (target < *mid)
            right = mid - 1;
        else if (target > *mid)
            left = mid + 1;
        else
            return mid - vec.begin();
    }
    return -(left - vec.begin() + 1);
}

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
        for (auto s : svec) // add or remove elements not allowed in for loop or iteration
        {
            words += s;
            words += ",";
        }
    cout << words << endl;
    vector<int> v5(5);
    std::iota(std::begin(v5), std::end(v5), 1); // natural numbers starting from 1
    cout << v5[0] << endl;
    for (auto &i : v5)
        i *= i;
    for (auto it = v5.begin(); it != v5.end(); ++it)
        cout << it - v5.begin() << ":" << *it << " ";
    cout << endl;
    for (int i = 0; i < v5.size(); ++i)
        cout << i << ":" << v5[i] << " ";
    cout << endl;
    cout << "binary search" << endl;
    cout << binarySearch(v5, 9) << endl;
    cout << binarySearch(v5, 10) << endl;
}
