//
//  507_Perfect_Number.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/28/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        int root = sqrt(num), sum = 1;
        for (int i = 2; i <= root; i++) {
            if (num % i == 0) {
                sum += i + num / i;
            }
        }
        if (num % root == root) {
            sum -= root;
        }
        return sum == num;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 507. Perfect Number, C++ ...\n\n";
    Solution sol;

    int num = 6;    // true

    bool r = sol.checkPerfectNumber(num);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}

