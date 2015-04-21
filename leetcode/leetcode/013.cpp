//
//  013.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/20/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        const int  n[] = {  1,   5,  10,  50, 100, 500, 1000};
        const char c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        int num = 0;
        int len = (int)s.length();
        int i = sizeof(n)/sizeof(int) - 1;
        int p = 0;
        while (p < len) {
            if (s[p] == c[i+2]) {
                num = num - n[i] * 2+ n[i+2];
                i--;
                p++;
            } else if (s[p] == c[i+1]) {
                num = num - n[i] * 2 + n[i+1];
                i--;
                p++;
            } else if (s[p] == c[i]) {
                num += n[i];
                p++;
            } else {
                i--;
            }
        }
        return num;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 013 Roman to Integer, C++ ... ...\n";
    
    Solution sol;
    string s = "XIV";
    cout << s << "    " << sol.romanToInt(s) << '\n';
    
    return 0;
}