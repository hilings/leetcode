//
//  006.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/12/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        int len = (int)s.length();
        string str;
        for (int r = 0; r < nRows; r++) {
            for (int i = r; i < len; i += 2*nRows - 2) {
                str += s[i];
                if (r != 0 && r != nRows - 1) {
                    int t = i + 2*nRows - 2 - 2*r;
                    if (t < len) {
                        str += s[t];
                    }
                }
            }
        }
        return str;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 006 ZigZag Conversion, C++ ... ...\n";
            //  0123456789012345
    string s = "PAYPALISHIRING";
    s = "0123456789";
    int nRows = 4;
    Solution sol;
    
    cout << s << "\n";
    cout << "Calculating...\n" << sol.convert(s, nRows) << "\n";
    
    return 0;
}
