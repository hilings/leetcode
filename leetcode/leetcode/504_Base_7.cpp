//
//  504_Base_7.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0) {
            return "-" + convertToBase7(-num);
        }
        string r = "";
        while (num > 0) {
            r = to_string(num%7) + r;
            num /= 7;
        }
        return r.empty() ? "0" : r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 504. Base 7, C++ ...\n\n";
    Solution sol;

    int num = 100;  // 202
    num = -7;  // -10

    string r = sol.convertToBase7(num);
    cout << r << '\n';

    return 0;
}

