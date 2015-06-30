//
//  043.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/19/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string s = "0";
        int l2 = (int)num2.size();
        for (int i = 0; i < l2; i++) {
            s = add(s, times(num1, num2[l2-1-i]-'0'));
            num1 += '0';
        }
        return s;
    }
    string add(string a, string b) {
        int la = (int)a.size();
        int lb = (int)b.size();
        int l = la < lb ? lb : la;
        string s = la < lb ? b : a;

        int carry = 0;
        for (int i = 0; i < l; i++) {
            int tmp = carry + (i<la ? a[la-1-i]-'0' : 0) + (i<lb ? b[lb-1-i]-'0' : 0);
            s[l-1-i] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        return carry ? "1"+s : s;
    }
    string times(string a, int b) {
        if (b == 0)
            return "0";
        int carry = 0;
        int l = (int)a.size();
        for (int i = 0; i < l; i++) {
            int tmp = (a[l-1-i]-'0') * b + carry;
            a[l-1-i] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        return carry ? string(1, carry+'0') + a : a;
    }
    string multiply2(string num1, string num2) {
        int l1 = (int)num1.size();
        int l2 = (int)num2.size();
        string s (l1+l2, '0');
        for (int i = l1-1; i >= 0; i--) {
            int carry = 0;
            for (int j = l2-1; j >= 0; j--) {
                int tmp = (s[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') + carry;
                s[i+j+1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            s[i] += carry;
        }
        size_t index = s.find_first_not_of("0");
        return index == string::npos ? "0" : s.substr(index);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 043 Multiply Strings, C++ ...\n\n";

    string num1 = "0", num2 = "0";
    Solution sol;
    //cout << sol.add(num1, num2);
    //cout << sol.times(num1, 0);
    cout << sol.multiply2(num1, num2);

    return 0;
}