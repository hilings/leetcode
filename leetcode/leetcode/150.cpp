//
//  150.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/3/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if (s == "+")
                    stk.push(a+b);
                else if (s == "-")
                    stk.push(a-b);
                else if (s == "*")
                    stk.push(a*b);
                else
                    stk.push(a/b);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 150. Evaluate Reverse Polish Notation, C++ ...\n\n";
    Solution sol;
    
    vector<string> tokens {
        //"2", "1", "+", "3", "*"		// 9
        "4", "13", "5", "/", "+"	// 6
    };
    
    int r = sol.evalRPN(tokens);
    cout << r << '\n';
    
    return 0;
}