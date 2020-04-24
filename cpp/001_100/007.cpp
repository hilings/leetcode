//
//  007.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/12/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long int z = 0;
        while (x != 0) {
            z = z * 10 + x % 10;
            x /= 10;
        }
        if (z > numeric_limits<int>::max() || z < numeric_limits<int>::min()) {
            return 0;
        }
        return (int)z;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 007 Reverse Integer, C++ ... ...\n";
    
    int x = 123;
    cout << x << '\n';
    Solution sol;
    
    for (int x = -123; x < 1; x++) {
        //cout << "x = " << x << ", z = " << sol.reverse(x) << '\n';
    }
    x = -1000000003;
    cout << "x = " << x << ", z = " << sol.reverse(x) << '\n';
    cout << numeric_limits<int>::max() << '\n';
    cout << numeric_limits<int>::min() << '\n';
    cout << abs(numeric_limits<int>::min());
    return 0;
}