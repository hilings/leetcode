//
//  592_Fraction_Addition_and_Subtraction.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/14/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return abs(a);
    }
public:
    string fractionAddition(string expression) {
        int A = 0, B = 1;
        for (string::size_type prev = 0, pos; prev < expression.size(); prev = pos) {
            pos = expression.find_first_of("+-", prev+1);
            string cur = expression.substr(prev, pos-prev);
            printf("cur = %s\n", cur.c_str());

            string::size_type d = cur.find('/');
            int a = stoi(cur.substr(0, d)), b = stoi(cur.substr(d+1));
            A = A*b + a*B;
            B *= b;
            int g = gcd(A, B);
            A = A/g;
            B = B/g;
        }
        return to_string(A) + "/" + to_string(B);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 592. Fraction Addition and Subtraction, C++ ...\n\n";
    Solution sol;

    string expression = "-1/2+1/2"; //0/1
    //expression = "1/6+5/6"; // 1/1
    expression = "-1/2+1/2+1/3";    // 1/3
    expression = "1/3-1/2"; // -1/6
    expression = "5/3+1/3"; // 2/1

    string r = sol.fractionAddition(expression);
    cout << r << '\n';
    return 0;
}
