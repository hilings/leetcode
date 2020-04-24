//
//  728_Self_Dividing_Numbers.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/21/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isSelfDividing(int n) {
        int tmp = n;
        while (tmp > 0) {
            int d = tmp % 10;
            if (d == 0 || n % d != 0) {
                return false;
            }
            tmp /= 10;
        }
        return true;
    }

  public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> r;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                r.push_back(i);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 728. Self Dividing Numbers, C++ ...\n\n";
    Solution sol;

    int left = 1;
    int right = 22; // 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22

    vector<int> r = sol.selfDividingNumbers(left, right);
    for (int a : r) {
        cout << a << '\n';
    }

    return 0;
}
