//
//  537_Complex_Number_Multiplication.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/8/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int p1 = (int)a.find('+'), r1 = stoi(a.substr(0, p1)), i1 = stoi(a.substr(p1+1));
        int p2 = (int)b.find('+'), r2 = stoi(b.substr(0, p2)), i2 = stoi(b.substr(p2+1));
        //printf("a = %d+%di\nb = %d+%di\n", r1, i1, r2, i2);
        int r = r1*r2 - i1*i2, i = r1*i2 + r2*i1;
        return to_string(r) + "+" + to_string(i) + "i";
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 537. Complex Number Multiplication, C++ ...\n\n";
    Solution sol;

    string a = "1+1i";
    a = "1+-1i";
    string b = "1+1i";
    b = "1+-1i";

    string r = sol.complexNumberMultiply(a, b);
    cout << r << '\n';

    return 0;
}
