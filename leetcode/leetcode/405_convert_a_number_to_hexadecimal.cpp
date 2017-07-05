//
//  405_convert_a_number_to_hexadecimal.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/28/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string r = "";
        while (num != 0) {
            int t = num & 15;
            r += t < 10 ? '0'+t : 'a'+t-10;
            num = num >> 4;
            if (num < 0) {
                num = num & 0xfffffff;
            }
        }
        reverse(r.begin(), r.end());
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 405. Convert a Number to Hexadecimal, C++ ...\n\n";
    Solution sol;
    
    int num = -1;
    string r = sol.toHex(num);
    cout << r << '\n';
    
    return 0;
}
