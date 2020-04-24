//
//  483_Smallest_Good_Base.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    long long int helper(long long int k, int m) {  // n = k^m + k^m-1 + ... + k + 1
        long long int r = 1;
        for (int i = m; i > 0; i--) {
            r = r*k+1;
        }
        return r;
    }
public:
    string smallestGoodBase(string n) {
        /*
         k >= 2 ~~~~> m < log2(n)
         n = k^m + k^m-1 + ... + 1 = k^(m+1)-1 / (k-1)
         k^m < n < (k+1)^m
         n^1/m-1 < k < n^1/m < k+1
         */
        long long int nn = stoll(n);
        for (int m = log2(nn); m >= 2; m--) {
            long long int k = (long long int)(pow(nn, pow(m, -1)));
            if (helper(k, m) == nn) {
                return to_string(k);
            }
        }
        return to_string(nn-1);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 483. Smallest Good Base, C++ ...\n\n";
    Solution sol;

    string n = "13";    // 3
    n = "4681"; // 8
    n = "1000000000000000000";  // 999999999999999999
    n = "470988884881403701";   // 686286299
    string r = sol.smallestGoodBase(n);
    cout << r << '\n';

    return 0;
}

