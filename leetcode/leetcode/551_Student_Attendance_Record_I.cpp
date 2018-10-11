//
//  551_Student_Attendance_Record_I.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int n = (int)s.size(), a = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                a++;
                if (a > 1) {
                    return false;
                }
            } else if (s[i] == 'L' && i+1 < n && s[i+1] == 'L' && i+2 < n && s[i+2] == 'L') {
                return false;
            }
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 551. Student Attendance Record I, C++ ...\n\n";
    Solution sol;

    string s = "PPALLP";    // true
    s = "PPALLL";    // false

    bool r = sol.checkRecord(s);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
