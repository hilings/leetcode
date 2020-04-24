//
//  343.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    vector<int> v;
public:
    int integerBreak0(int n) {
        if (n <= 3)
            return n-1;
        if (v.empty()) {
            v.push_back(0);
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            v.insert(v.end(), 55, 0);
        }
        if (v[n] != 0)
            return v[n];
        int r = 1;
        for (int i = 2; i <= n/2; i++) {
            r = max(r,
                    i * (n-i <= 3 ? n-i : integerBreak0(n-i))
                    );
        }
        v[n] = r;

        return r;
    }

    int integerBreak1(int n) {
        if (n <= 3)
            return n-1;
        int r = 1;
        while (n > 4) {
            r *= 3;
            n -= 3;
        }
        return r*n;
    }

    int integerBreak(int n) {
        if (n <= 3)
            return n-1;
        if (n%3 == 0)
            return pow(3, n/3);
        if (n%3 == 1)
            return 4*pow(3, (n-4)/3);
        return 2*pow(3, (n-2)/3);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 343. Integer Break, C++ ...\n\n";
    Solution sol;

    // 57	// 1162261467
    // 58	// 1549681956
    for (int i = 2; i <= 58; i++) {
        int r0 = sol.integerBreak0(i);
        cout << i << " -> " << r0 << '\n';
        
        int r1 = sol.integerBreak1(i);
        cout << i << " -> " << r1 << '\n';
        
        int r = sol.integerBreak(i);
        cout << i << " -> " << r << '\n';
    }
    
    return 0;
}
