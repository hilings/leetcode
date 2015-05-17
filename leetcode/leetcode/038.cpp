//
//  038.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/14/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            cout << i << " -> " << s << '\n';
            int count = 1;
            string tmp = "";
            int j;
            for (j = 1; j < s.size(); j++) {
                if (s[j] == s[j-1])
                    count++;
                else {
                    tmp += to_string(count) + s[j-1];
                    count = 1;
                }
            }
            tmp += to_string(count) + s[j-1];
            s = tmp;
        }
        cout << n << " -> " << s << '\n';
        return s;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 038 Count and Say, C++ ...\n\n";

    int n = 20;
    Solution sol;
    sol.countAndSay(n);

    return 0;
}