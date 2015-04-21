//
//  008.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/12/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len = (int)str.size();
        int i = 0;
        while (i < len && isspace((int)str[i])){
            i++;
        }
        
        int sign = 1;
        if (i < len && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i] == '+') ? 1 : -1;
            i++;
        }

        long int z = 0;
        while (i < len && isdigit(str[i]) && z < numeric_limits<int>::max()) {
            z = z * 10 + (int)(str[i]-'0');
            i++;
        }
        if (z > numeric_limits<int>::max()) {
            return (sign == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
        }
        return (int)(sign * z);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 008 String to Integer (atoi), C++ ... ...\n";
    
    string str = "2147483648";
    cout << str << '\n';
    
    Solution sol;
    cout << sol.myAtoi(str) << '\n';
    
    cout << numeric_limits<int>::max() << '\n';
    cout << numeric_limits<int>::min() << '\n';
    
    return 0;
}