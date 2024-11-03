#ifndef LEETCODE_KMP1D_HPP
#define LEETCODE_KMP1D_HPP

#include <utility>
#include <vector>
#include <string>

using namespace std;

class KMP1D {
public:
    vector<size_t> restart{0};
    string n;

    KMP1D(string n) : n(n) {
        size_t m = n.size();
        restart.resize(m);
        for (size_t i = 1, j = 0; i < m;) {
            if (n[i] == n[j]) restart[i++] = ++j;
            else if (j > 0) j = restart[j - 1];
            else i++;
        }
    }

    int search(const string &h) {
        size_t i, m = restart.size();
        int j;
        for (i = 0, j = 0; i < h.size() && j < m;) {
            if (h[i] == n[j]) {
                i++;
                j++;
            } else if (j > 0) j = static_cast<int>(restart[j - 1]);
            else i++;
        }
        return j == m ? j : -1;
    }

    bool inHaystack(const string &h) {
        return search(h) != -1;
    }

};

#endif //LEETCODE_KMP1D_HPP
