#ifndef MYCALENDARI_HPP
#define MYCALENDARI_HPP

#include <iterator>
#include <map>

using namespace std;

class MyCalendar {
public:
    map<int, int> booked;

    MyCalendar() = default;

    bool book(int start, int end) {
        auto nex = booked.upper_bound(start); // bisect_right:upper_bound, first greater key
        if (nex != booked.end() && nex->first < end) return false;
        if (nex != booked.begin()) // cannot compare with < or <=
            if (auto pre = prev(nex); pre->second > start) return false;
        booked[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


#endif //MYCALENDARI_HPP
