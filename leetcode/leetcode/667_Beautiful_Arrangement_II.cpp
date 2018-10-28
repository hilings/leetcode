//
//  667_Beautiful_Arrangement_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> r;
        for (int start = 1; start <= n; start += k+1) {    // back and forth within k range, then next range
            for (int i = start, j = min(start+k, n); i <= j; ) {
                r.push_back(i++);
                if (i <= j) {
                    r.push_back(j--);
                }
            }
        }
        return r;
    }

    vector<int> constructArray2(int n, int k) {
        vector<int> r;
        for (int i = 1, j = n; i <= j; ) {
            if (k > 1) {    // back and forth from two ends for k-1 distance
                r.push_back(k--%2 == 1 ? i++ : j--);    // odd from left, even from right
            } else {    // push the rest one by one
                r.push_back(i++);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 667. Beautiful Arrangement II, C++ ...\n\n";
    Solution sol;

    int n = 6;
    int k = 3;

    vector<int> r = sol.constructArray(n, k);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r2 = sol.constructArray2(n, k);
    for (int a: r2) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
