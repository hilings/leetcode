//
//  278.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    return false;
};

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while (i < j) {
            int m = i+(j-i)/2;  // (i+j)/2 may overflow
            if (isBadVersion(m)) {
                j = m;
            } else {
                i = m+1;
            }
        }
        return i;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 278. First Bad Version, C++ ...\n\n";
    Solution sol;

    int n = 9;

    int r = sol.firstBadVersion(n);
    cout << r << '\n';

    return 0;
}