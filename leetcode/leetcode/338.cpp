//
//  338.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits0(int num) {
        vector<int> r;
        for (int i = 0; i <= num; i++) {
            int t = i, k = 0;
            while (t > 0) {
                if ((t&1) == 1)
                    k++;
                t = t >> 1;
            }
            r.push_back(k);
        }
        return r;
    }

    vector<int> countBits(int num) {
        vector<int> r {0};
        for (int i = 1; i <= num; i++) {
            r.push_back(i%2 == 0 ? r[i/2] : (r[i-1]+1));
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 338. Counting Bits, C++ ...\n\n";
    Solution sol;

    int num = 5;
    vector<int> r0 = sol.countBits0(num);
    for (int i: r0) {
        cout << i << " ";
    }
    
    cout << '\n';
    
    vector<int> r = sol.countBits(num);
    for (int i: r) {
        cout << i << " ";
    }
    
    return 0;
}
