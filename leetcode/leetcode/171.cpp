//
//  171.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (char c: s) {
            ret = 26*ret + c-'A'+1;
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 171. Excel Sheet Column Number, C++ ...\n\n";
    Solution sol;

    string s = "ZZ";
    int r = sol.titleToNumber(s);
    cout << r << '\n';
    
    return 0;
}