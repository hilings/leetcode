//
//  241.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> solve(vector<int>& v, int start, int end) {
        vector<int> ret;
        if (start == end)
            ret.push_back(v[start]);
        for (int i = start+1; i < end; i += 2) {
            vector<int> left = solve(v, start, i-1);
            vector<int> right = solve(v, i+1, end);
            for (int a: left) {
                for (int b: right) {
                    if (v[i] == 1) {	// +
                        ret.push_back(a+b);
                    } else if (v[i] == -1) {	// -
                        ret.push_back(a-b);
                    } else {	// *
                        ret.push_back(a*b);
                    }
                }
            }
        }
        return ret;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> v;
        for (int i = 0; i < input.size(); i++) {
            if (isdigit(input[i])) {
                int num = input[i]-'0';
                while (i+1 < input.size() && isdigit(input[i+1]))
                    num = 10*num + input[++i]-'0';
                v.push_back(num);
            } else if (input[i] == '+') {
                v.push_back(1);
            } else if (input[i] == '-') {
                v.push_back(-1);
            } else {	// *
                v.push_back(2);
            }
        }
        /*
         for (int i = 0; i < v.size(); i++) {
             if (i % 2 == 0) {
                 cout << v[i];
             } else if (v[i] == 1) {
                 cout << " + ";
             } else if (v[i] == -1) {
                 cout << " - ";
             } else {
                 cout << " * ";
             }
         }
         cout << '\n';
         */
        return solve(v, 0, (int)v.size()-1);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 241. Different Ways to Add Parentheses, C++ ...\n\n";
    Solution sol;
    
    string input = "2-1-1";
    input = "2*3-4*5";
    
    vector<int> r = sol.diffWaysToCompute(input);
    for (int a: r) {
        cout << a << ' ';
    }
    
    return 0;
}