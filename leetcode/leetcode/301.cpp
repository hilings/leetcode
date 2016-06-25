//
//  301.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/16/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void solve(vector<string>& ret, string& s, int pos, string path, int left, int right) {
        if (pos == s.size()) {
            if (left == right) {
                if (!ret.empty() && path.size() > ret.back().size())
                    ret.clear();
                if (ret.empty() || (path.size() == ret.back().size() && find(ret.begin(), ret.end(), path) == ret.end()))
                    ret.push_back(path);
            }
            return;
        }
        if (s[pos] == '(') {
            solve(ret, s, pos+1, path+"(", left+1, right);
            solve(ret, s, pos+1, path, left, right);
        } else if (s[pos] == ')') {
            if (left > right)
                solve(ret, s, pos+1, path+")", left, right+1);
            solve(ret, s, pos+1, path, left, right);
        } else {
            solve(ret, s, pos+1, path+s[pos], left, right);
        }
    }

    void solve2(vector<string>& ret, string s, int lasti, int lastj, char removing) {	// 2
        for (int count = 0, i = lasti; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')')
                continue;
            count += s[i] == removing ? -1 : 1;
            if (count >=0)
                continue;

            for (int j = lastj; j <= i; j++) {
                if (s[j] == removing && (j == lastj || s[j-1] != removing))
                    solve2(ret, s.substr(0, j) + s.substr(j+1), i, j, removing);
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (removing == ')')
            solve2(ret, s, 0, 0, '(');
        else
            ret.push_back(s);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        solve(ret, s, 0, "", 0, 0);
        return ret;
    }

    vector<string> removeInvalidParentheses2(string s) {
        vector<string> ret;
        solve2(ret, s, 0, 0, ')');
        return ret;
    }

};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 301. Remove Invalid Parentheses, C++ ...\n\n";
    Solution sol;
    
    string s = "()())()";	// ["()()()", "(())()"]
    //s = "(a)())()";	// ["(a)()()", "(a())()"]
    //s = ")(";	// [""]
    
    vector<string> r = sol.removeInvalidParentheses2(s);
    for (string str: r) {
        cout << "\"" << str << "\"\n";
    }
    
    
    
    
    return 0;
}