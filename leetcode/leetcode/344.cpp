//
//  344.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.size()-1; i < j; i++ & j--) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
        return s;
    }
    string reverseString2(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 344. Reverse String, C++ ...\n\n";
    Solution sol;

    string s = "hello";

    string r = sol.reverseString(s);
    cout << r << '\n';

    string r2 = sol.reverseString2(s);
    cout << r2 << '\n';
    
    return 0;
}
