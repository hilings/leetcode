//
//  264.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber0(int n) {
        int ret[n], i2 = 0, i3 = 0, i5 = 0, count = 1;
        ret[0] = 1;
        while (count < n) {
            int next = min(2*ret[i2], min(3*ret[i3], 5*ret[i5]));
            ret[count++] = next;
            if (next == 2*ret[i2])
                i2++;
            if (next == 3*ret[i3])
                i3++;
            if (next == 5*ret[i5])
                i5++;
        }
        /*
         for (int i = 0; i < n; i++) {
         cout << ret[i] << '\n';
         }
         */
        return ret[n-1];
    }
    int nthUglyNumber(int n) {
        static vector<int> ret {1};
        static int i2 = 0, i3 = 0, i5 = 0;
        while (ret.size() < n) {
            int next = min(2*ret[i2], min(3*ret[i3], 5*ret[i5]));
            ret.push_back(next);
            if (next == 2*ret[i2])
                i2++;
            if (next == 3*ret[i3])
                i3++;
            if (next == 5*ret[i5])
                i5++;
        }
        return ret[n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 264. Ugly Number II, C++ ...\n\n";
    Solution sol;
    
    int n = 10;
    
    int r = sol.nthUglyNumber(n);
    cout << r << '\n';
    
    return 0;
}