//
//  065.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/18/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    void log(int i, string s) {
        cout << i << " " << s << '\n';
    }

    bool myisdigit(string s, int i) {
        if (i < 0 || i >= s.size())
            return false;
        return isdigit(s[i]);
    }

    bool isNumber(string s) {
        int i = (int)s.find_first_not_of(' ');
        log(i, "leading space");

        if (s[i] == '+' || s[i] == '-') {
            log(i, "+/-");
            i++;
        }

        while (isdigit(s[i])) {
            log(i, "d");
            i++;
        }

        if (s[i] == '.') {
            log(i, ".");
            if (!myisdigit(s, i-1) && !myisdigit(s, i+1))
                return false;
            i++;
        }

        while (isdigit(s[i])) {
            log(i, "d");
            i++;
        }

        if (s[i] == 'e') {
            log(i, "e");
            if (!myisdigit(s, i-1) && !myisdigit(s, i-2))
                return false;
            if (!myisdigit(s, i+1) && !myisdigit(s, i+2))
                return false;
            i++;

            if ((s[i] == '+' || s[i] == '-') && myisdigit(s, i+1)) {
                log(i, "+/-");
                i++;
            }
        }

        while (isdigit(s[i])) {
            log(i, "d");
            i++;
        }

        while (s[i] == ' ') {
            log(i, "trailing space");
            i++;
        }
        
        return i == s.size();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 065 Valid Number, C++ ...\n\n";
    Solution sol;
    
    string s[] = {
        "4e+",	//false
        "6+1",	//false
        " 005047e+6",	//true
        "e9", 	//false
        "46.e3",	//true
        " 1. " };
    
    bool r = sol.isNumber(s[0]);
    string r2 = r ? "true" : "false";
    cout << r2 << '\n';
    
    return 0;
}
