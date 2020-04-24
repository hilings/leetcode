//
//  091.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n[s.size()];
        n[0] = s[0] == '0' ? 0 : 1;
        for (size_t i = 1; i < s.size(); i++) {
            n[i] = 0;
            if (s[i] != '0')
                n[i] += n[i-1];
            int tmp = stoi(s.substr(i-1,2));
            if (tmp >= 10 && tmp <= 26)
                n[i] += i==1 ? 1 : n[i-2];
        }
        return n[s.size()-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 091 Decode Ways, C++ ...\n\n";
    Solution sol;

    string s = "00";
    int r = sol.numDecodings(s);
    cout << r << '\n';
    
    return 0;
}