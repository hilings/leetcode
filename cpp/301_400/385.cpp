//
//  385.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/14/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger r;
        if (s[0] == '[') {	// nested list
            int i = 1;
            for (int j = 1, bracket = 0; j < s.size()-1; j++) {
                if (s[j] == '[') {
                    bracket++;
                } else if (s[j] == ']') {
                    bracket--;
                } else if (s[j] == ',' && bracket == 0) {
                    r.add(deserialize(s.substr(i, j-i)));
                    i = j+1;
                }
            }
            if (i < s.size()-1) {
                r.add(deserialize(s.substr(i, s.size()-1-i)));
            }
        } else {	// single integer
            r.setInteger(stoi(s));
        }
        return r;
    }

    vector<string> split(string s) {	// split into vector of comma separated substrings
        vector<string> v;
        int i = 0;
        for (int j = 0, bracket = 0; j < s.size(); j++) {
            if (s[j] == '[') {
                bracket++;
            } else if (s[j] == ']') {
                bracket--;
            } else if (s[j] == ',' && bracket == 0) {
                v.push_back(s.substr(i, j-i));
                i = j+1;
            }
        }
        if (i < s.size()) {
            v.push_back(s.substr(i));
        }
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 385. Mini Parser, C++ ...\n\n";
    Solution sol;
    
    string s = "324";
    string s2 = "[123,[456,[789]]]";
    
    //sol.deserialize(s);
    for (string str: sol.split(s2)) {
        cout << str << '\n';
    }
    
    return 0;
}
