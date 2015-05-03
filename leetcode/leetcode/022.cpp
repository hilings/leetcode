//
//  022.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/28/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if (n == 0)
            return v;
        
        queue<string> q;
        q.push("(");
        while(q.front().size() < 2*n) {
            string s = q.front();
            q.pop();
            int l = 0, r = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(')
                    l++;
                else
                    r++;
            }
            if (l<n)
                q.push(s+"(");
            if (l>r)
                q.push(s+")");
        }
        while (q.size()) {
            v.push_back(q.front());
            q.pop();
        }
        return v;
    }
};

void printVector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 022 Generate Parentheses, C++ ... ...\n";
    
    int n = 4;
    Solution sol;
    
    vector<string> v = sol.generateParenthesis(n);
    printVector(v);
    cout << v.size();
    
    /*
    vector<string> expected4 = {"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"};
    vector<string> expected5 = {"((((()))))","(((()())))","(((())()))","(((()))())","(((())))()","((()(())))","((()()()))","((()())())","((()()))()","((())(()))","((())()())","((())())()","((()))(())","((()))()()","(()((())))","(()(()()))","(()(())())","(()(()))()","(()()(()))","(()()()())","(()()())()","(()())(())","(()())()()","(())((()))","(())(()())","(())(())()","(())()(())","(())()()()","()(((())))","()((()()))","()((())())","()((()))()","()(()(()))","()(()()())","()(()())()","()(())(())","()(())()()","()()((()))","()()(()())","()()(())()","()()()(())","()()()()()"};
    cout << expected4.size();
    cout << expected5.size();
    */
    
    return 0;
}