//
//  258.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int ret = 0;
        while (num > 0) {
            ret += num % 10;
            num /= 10;
            if (ret > 9)
                ret -= 9;
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 258. Add Digits, C++ ...\n\n";
    Solution sol;

    int num = 38;
    
    int r = sol.addDigits(num);
    cout << r << '\n';
    
    return 0;
}