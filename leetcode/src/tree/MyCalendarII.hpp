#ifndef MYCALENDARII_HPP
#define MYCALENDARII_HPP

#include <map>

using namespace std;

class MyCalendarTwo {
public:
    map<int, int> bCnt;
    int maxB;

    explicit MyCalendarTwo(int maxB) : maxB(maxB) {
    }

    bool book(int start, int end) {
        bCnt[start]++;
        bCnt[end]--;

        int overlap = 0;
        for (auto t = bCnt.begin(); t != bCnt.end(); ++t) {
            overlap += t->second;
            if (overlap > maxB) {
                bCnt[start]--;
                bCnt[end]++;
                if (bCnt[start] == 0) bCnt.erase(start);
                if (bCnt[end] == 0) bCnt.erase(end);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

#endif //MYCALENDARII_HPP
