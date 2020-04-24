//
//  032.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/10/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = (int)s.size();
        stack<int> cache;
        unordered_map<int, int> map;
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                cache.push(i);
            else {
                if (!cache.empty()) {
                    int top = cache.top();
                    map[top] = i - top + 1;
                    cache.pop();
                } else {
                    while (!cache.empty())
                        cache.pop();
                }
            }
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            cout << it->first << it->second << '\n';
            while (map.find(it->first + it->second) != map.end())
                it->second += map.find(it->first + it->second)->second;
            if (it->second > max)
                max = it->second;
        }
        cout << "\ncount = " << max;
        return max;
    }

    int longestValidParentheses2(string s) {
        int n = (int)s.size();
        int count = 0;
        stack<int> cache;
        cache.push(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                cache.push(i);
            else if (cache.top() != -1 && s[cache.top()] == '(') {
                cache.pop();
                count = max(count, i - cache.top());
            } else
                cache.push(i);
        }
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 032 Longest Valid Parentheses, C++ ...\n\n";

    string s = "(()";
    s = "()(()";
    s = "()";
    cout << "s = " << s << '\n';

    Solution sol;
    cout << sol.longestValidParentheses2(s);

    return 0;
}