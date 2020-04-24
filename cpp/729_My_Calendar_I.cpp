//
//  729_My_Calendar_I.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/21/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class MyCalendar {
    map<int, int> om;

  public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        auto it = om.lower_bound(start);
        if ((it == om.begin() || prev(it)->second <= start) && (it == om.end() || end <= it->first)) {
            om[start] = end;
            printf("[%d, %d] true\n", start, end);
            return true;
        }
        printf("[%d, %d] false\n", start, end);
        return false;
    }

    void print() {
        for (auto p : om) {
            cout << "[" << p.first << ", " << p.second << "]\n";
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 729. My Calendar I, C++ ...\n\n";

    MyCalendar sol = MyCalendar();
    // sol.book(10, 20); // returns true
    // sol.book(15, 25); // returns false
    // sol.book(20, 30); // returns true

    sol.book(47, 50); // true
    sol.book(33, 41); // true
    sol.book(39, 45); // false
    sol.book(33, 42); // false
    sol.book(25, 32); // true
    sol.book(26, 35); // false
    sol.book(19, 25); // true
    sol.book(3, 8);   // true
    sol.book(8, 13);  // true
    sol.book(18, 27); // false

    // sol.book(37, 50); // true
    // sol.book(33, 50); // false
    // sol.book(4, 17);  // true
    // sol.book(35, 48); // false
    // sol.book(8, 25);  // false

    sol.print();

    return 0;
}
