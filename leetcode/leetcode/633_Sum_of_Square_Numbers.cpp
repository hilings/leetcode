//
//  633_Sum_of_Square_Numbers.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/23/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a*a <= c/2; a++) {
            int b = (int)sqrt(c-a*a);
            if (a*a + b*b == c) {
                printf("%d*%d + %d*%d = %d\n", a, a, b, b, c);
                return true;
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 633. Sum of Square Numbers, C++ ...\n\n";
    Solution sol;

    int c = 1;

    bool r = sol.judgeSquareSum(c);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
