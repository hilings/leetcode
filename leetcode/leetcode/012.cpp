//
//  012.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/19/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const int    n[] = {  1,    4,   5,    9,  10,   40,  50,   90, 100,  400, 500,  900, 1000};
        const string c[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

        string str = "";
        int i = sizeof(n) / sizeof(int) - 1;
        while (num) {
            if (num < n[i]) {
                i--;
                continue;
            }
            str += c[i];
            num -= n[i];
        }
        return str;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 012 Integer to Roman, C++ ... ...\n";
    
    Solution sol;

    for (int num = 0; num < 15; num++) {
        cout << num << "    " << sol.intToRoman(num) << '\n';
    }
    
    return 0;
}