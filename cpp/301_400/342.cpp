//
//  342.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPowerOfFour0(int num) {
        for (int i = 1; i > 0 && num >= i; i *= 4) {
            if (num == i)
                return true;
        }
        return false;
    }

    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num-1)) == 0 && (num & 0x55555555) > 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 342. Power of Four, C++ ...\n\n";
    Solution sol;

    int num =
    16;	// true
    //1162261466;	// false
    ;
    bool r0 = sol.isPowerOfFour0(num);
    cout << (r0 ? "true" : "false") << '\n';

    bool r = sol.isPowerOfFour(num);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}
