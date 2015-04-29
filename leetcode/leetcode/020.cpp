//
//  020.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/28/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (stack.empty())
                stack.push(s[i]);
            else if ( (s[i] == ')' && stack.top() == '(') || (s[i] == ']' && stack.top() == '[') || (s[i] == '}' && stack.top() == '{') )
                stack.pop();
            else
                stack.push(s[i]);
        }
        return stack.empty();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 020 Valid Parentheses, C++ ... ...\n";
    
    string s = "]";
    cout << s << '\n';
    
    Solution sol;
    cout << (sol.isValid(s) ? "True" : "False") << '\n';
    
    return 0;
}
