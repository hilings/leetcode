//
//  263.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 263. Ugly Number, C++ ...\n\n";
    Solution sol;

    int num = 14;

    bool r = sol.isUgly(num);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}