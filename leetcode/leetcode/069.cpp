//
//  069.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/23/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long r = 1;
        while (r*r <= x)
            r *= 2;
        int step = (int)r / 2;
        while (step) {
            if ((r-step)*(r-step) > x)
                r -= step;
            step /= 2;
        }
        return (int)r-1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 069 Sqrt(x), C++ ...\n\n";
    Solution sol;

    int x = 2147483647;
    int r = sol.mySqrt(x);
    cout << r << "\n\n";
    
    cout << floor(sqrt(x));
    
    return 0;
}