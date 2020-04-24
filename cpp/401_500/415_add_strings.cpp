//
//  415_add_strings.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string r = "";
        for (int i = (int)num1.size()-1, j = (int)num2.size()-1, c = 0; i >= 0 || j >= 0 || c > 0; i--, j--) {
            int k = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + c;
            c = k / 10;
            r += '0' + k % 10;
        }
        reverse(r.begin(), r.end());
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 415. Add Strings, C++ ...\n\n";
    Solution sol;

    string num1 = "1";
    string num2 = "9";
    string r = sol.addStrings(num1, num2);
    cout << r << '\n';
    
    return 0;
}
