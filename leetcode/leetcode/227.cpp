//
//  227.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/10/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        deque<int> q;
        s += "+0";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') {
                continue;
            } else if (c == '+') {
                q.push_back(1);
            } else if (c == '-') {
                q.push_back(-1);
            } else if (c == '*') {
                q.push_back(2);
            } else if (c == '/') {
                q.push_back(-2);
            } else {
                int val = c-'0';
                while (i+1<s.size() && isdigit(s[i+1])) {
                    val = 10*val + s[++i]-'0';
                }
                cout << val << '\n';
                if (!q.empty() && (q.back() == 2 || q.back() == -2)) {
                    int op = q.back();
                    q.pop_back();
                    int tmp = q.back();
                    q.pop_back();
                    cout << tmp << (op == 2 ? '*' : '/') << val << '\n';
                    val = op == 2 ? tmp * val : tmp / val;
                }
                if (q.size() >= 3) {
                    int tmp = q.front();
                    q.pop_front();
                    int op = q.front();
                    q.pop_front();
                    cout << tmp << (op == 1 ? '+' : '-') << q.front() << '\n';
                    q.front() = op == 1 ? tmp+q.front() : tmp-q.front();
                }
                q.push_back(val);
            }
        }
        return q.front();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 224. Basic Calculator, C++ ...\n\n";
    Solution sol;
    
    string s = "3+2*2";	// 7
    s = " 3/2 ";	// 1
    s = " 3+5 / 2 ";	// 5
    s = "2+3*2+4";
    
    int r = sol.calculate(s);
    cout << r << '\n';
    
    return 0;
}