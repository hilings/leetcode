//
//  067.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/21/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            return addBinary(b, a);
        int i = (int)a.size()-1, j = (int)b.size()-1, c = 0;
        while (j >= 0) {
            int t = a[i]-'0' + b[j]-'0' + c;
            a[i] = '0' + t%2;
            c = t / 2;
            i--;
            j--;
        }
        while (i >= 0) {
            int t = a[i]-'0' + c;
            a[i] = '0' + t%2;
            c = t / 2;
            i--;
        }
        if (c == 1)
            a = "1"+a;
        return a;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 067 Add Binary, C++ ...\n\n";
    Solution sol;
    
    string a = "110";
    string b = "111";
    
    string r = sol.addBinary(a, b);
    cout << r;
    
    return 0;
}