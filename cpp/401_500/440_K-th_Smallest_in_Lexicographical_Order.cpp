//
//  440_K-th_Smallest_in_Lexicographical_Order.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/15/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        for (k--; k > 0;) {
            int count = 0;
            for (long start = prefix, end = start+1; start <= n; start *= 10, end *= 10) {
                count += min((long)n+1, end) - start;
            }
            if (k >= count) {
                k -= count;
                prefix++;
            } else {
                k--;
                prefix *= 10;
            }
        }
        return prefix;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 440. K-th Smallest in Lexicographical Order, C++ ...\n\n";
    Solution sol;

    int n = 13;
    int k = 2;  // 10
    n = 681692778;
    k = 351251360;  // 416126219
    int r = sol.findKthNumber(n, k);
    cout << r << '\n';

    return 0;
}
