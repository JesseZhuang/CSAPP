#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "hello world!"
              << "\n";
    cout << "arg count: " << argc << endl
              << "args: " << argv[0] << ", " << argv[1] << endl;

    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string &word : msg)
        cout << word, cout << " "; // multiple statements with comma on one line. int i; bool b need semicolon
    cout << endl;
    return 0;
}