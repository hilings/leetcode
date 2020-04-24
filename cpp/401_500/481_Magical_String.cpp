//
//  481_Magical_String.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/31/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> v {1};
        int r = 1;
        for (int i = 1; v.size() < n; i++) {
            int k = 3 - v.back();
            v.push_back(k);
            r += k == 1 ? 1 : 0;
            if (v.size() < n && v[i] == 2) {
                v.push_back(k);
                r += k == 1 ? 1 : 0;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 481. Magical String, C++ ...\n\n";
    Solution sol;

    int n = 6;
    int r = sol.magicalString(n);
    cout << r << '\n';
    cout << "1221121221221121122" << '\n';

    return 0;
}
