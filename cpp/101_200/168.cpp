//
//  168.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while (n) {
            ret.insert(0, 1, 'A' + (n-1)%26);
            n = (n-1) / 26;
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 168. Excel Sheet Column Title, C++ ...\n\n";
    Solution sol;
    for (int n = 0; n <= 26*27+1; n++) {
        string r = sol.convertToTitle(n);
        cout << n << ": " << r << '\n';
    }
    
    return 0;
}